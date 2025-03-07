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
const ll mod = 1e9 + 7, MAXN = 2e5 + 5;
typedef vector<int> vi;
typedef pair<int, pair<int, int>> piii;

vector<int> bfs(int start, int n, vector<vi> &g) {
    vector<int> dist(n + 5, -1);
    queue<int> q({start});
    dist[start] = 0;

    while(!q.empty()) {
        int u = q.front();
        q.pop();

        for(int &nxt : g[u])
            if(dist[nxt] == -1) {
                dist[nxt] = dist[u] + 1;
                q.push(nxt);
            }
    }
    return dist;
}

int32_t main() {
    int n;
    cin >> n;

    vector<vector<int>> g(n+1);
    vector<int> sz(n + 1);
    for(int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }

    vi da = bfs(1, n, g);

    int curEndp = 1;
    for(int i = 1; i <= n; i++)
        if(da[i] > da[curEndp])
            curEndp = i;
    
    vi db = bfs(curEndp, n, g);
    for(int i = 1; i <= n; i++)
        if(db[i] > db[curEndp])
            curEndp = i;
    da = bfs(curEndp, n, g);

    for(int i = 1; i <= n; i++)
        cout << max(da[i], db[i]) << " ";
    cout << endl;
    
}