#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <chrono>
#define pb push_back
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define endl '\n'
#define ll long long
#define f first
#define fin cin
#define fout cout
#define s second
#define int long long
#define FAST cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
#define debug(x) cerr << "DEBUG " << x << endl
#define debug2(x, y) cerr << "DEBUG " << x << " " << y << endl
#define debug3(x, y, z) cerr << "DEBUG " << x << " " << y << " " << z << endl
#define debug4(x, y, z, o) cerr << "DEBUG " << x << " " << y << " " << z << " " << o << endl
#define all(x) x.begin(), x.end()
#define left esquerda
#define lb lower_bound
#define right direita
using namespace std;
void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}
typedef pair<ll, ll> pii;
typedef vector<vector<char>> mat;
typedef pair<int, string> pis;
const ll mod = 1e9 + 7, MAXN = 505;
typedef vector<int> vi;
typedef pair<int, pair<int, int>> piii;

typedef struct Edge {
    int u, v, cap, flow = 0;
    Edge(int _u, int _v, int _cap, int _flow = 0) {
        u = _u;
        v = _v;
        cap = _cap;
        flow = _flow;
    }
    Edge() {};
} Edge;


vector<Edge> edges;
vector<int> g[MAXN], last, L;
int n, m;

void addEdge(int u, int v, int f, bool directed = true) {
    if(u == v) return;
    edges.pb({u, v, f, 0});
    g[u].pb(edges.size() - 1);

    edges.pb({v, u, (directed ? 0 : f), 0});
    g[v].pb(edges.size() - 1);
}

bool BFS(int start, int target) {
    L.assign(n + 1, 0);
    queue<int> fila;
    fila.push(start);
    L[start] = 1;

    while(!fila.empty()) {
        int next = fila.front();
        fila.pop();
        
        if(next == target)
            return true;

        for(int &a : g[next]) {
            Edge &i = edges[a];
            if(i.cap  - i.flow == 0)
                continue;
            
            if(!L[i.v]) {
                L[i.v] = L[next] + 1;
                fila.push(i.v);
            }
        }
    }
    
    return false;
}

ll DFS(int u, int target, ll bottleneck = LINF) {
    if(u == target)
        return bottleneck;
        
    for(int &nb = last[u]; nb < g[u].size(); nb++) {
        Edge &i = edges[g[u][nb]];
        if(L[i.v] <= L[u] || i.cap - i.flow == 0)
            continue;

        ll f = DFS(i.v, target, min(bottleneck, i.cap - i.flow));
        if(f) {
            i.flow += f;
            Edge &back = edges[g[u][nb]^1];
            back.flow -= f;
            
            return f;
        }
    }

    return 0;
}

int32_t main() {
    int m;
    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        int a, b, f;
        cin >> a >> b >> f;
        addEdge(a, b, f);
    }

    ll ans = 0;
    while(BFS(1, n)) {
        last.assign(n + 5, 0);
        while(ll f = DFS(1, n, INF))
            ans += f;
    }

    cout << ans << endl;
    for(int i = 0; i < edges.size(); i+= 2) {
        int f = max(0LL, edges[i].flow);
        cout << f << endl;
    }
}