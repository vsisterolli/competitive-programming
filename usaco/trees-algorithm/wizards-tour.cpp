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

vector<int> ans;
vector<int> g[MAXN], h(MAXN);

pii dfs(int u, int p = 1) {
    vector<pii> edges;
    for(int &i : g[u]) {
        if(i == p)
            continue;
        
        if(!h[i]) {
            h[i] = u + 1;
            pii sb = dfs(i, u);
            if(sb.f != -1) {
                ans.pb(u);
                ans.pb(i);
                ans.pb(sb.f);
            }
            else edges.pb({i, u});
        }
        else if(h[i] < h[u]) 
            edges.pb({i, u});
    }

    for(int i = 0; i + 1 < edges.size(); i += 2) {
        ans.pb(edges[i].f);
        ans.pb(u);
        ans.pb(edges[i + 1].f);
    }

    if(edges.size() & 1)
        return edges.back();
    else return {-1, -1};

  
}

void solve() {
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }

    for(int i = 1; i <= n; i++)
        if(!h[i]) {
            h[i] = 1;
            dfs(i);
        }

    cout << ans.size() / 3 << endl;
    for(int i = 0; i + 2 < ans.size(); i += 3)
        cout << ans[i] << " " << ans[i + 1] << " " << ans[i + 2] << endl;
}

int32_t main() {
    int ct = 1;
    // cin >> ct;
    while(ct--)
        solve();
    return 0;
}