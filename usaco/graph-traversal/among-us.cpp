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
const ll mod = 1e9 + 7, MAXN = 5e5 + 5;
typedef vector<int> vi;
typedef pair<int, pair<int, int>> piii;

vector<int> g[MAXN][2], ng[MAXN];
vector<int> comp[MAXN], scc(MAXN), nc;
vector<bool> used(MAXN), color(MAXN);

void dfs2(int u, int curComp) {
    used[u] = true;
    comp[curComp].push_back(u);
    scc[u] = curComp;

    for(int &i : g[u][1]) 
        if(!used[i])
            dfs2(i, curComp);
    
}

bool dans = true;

void dfs(int u) {
    used[u] = 1;
    nc.push_back(u);
    
    for(int &i : ng[u]) {
        if(!used[i]) {
            color[i] = !color[u];
            dfs(i);
        }
        else if(used[i] && color[i] == color[u])
            dans = false;
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        g[i][0].clear();
        g[i][1].clear();
        ng[i].clear();
        comp[i].clear();
        nc.clear();
        used[i] = 0;
        color[i] = 0;
        scc[i] = 0;
    }
    dans = true;

    for(int i = 0; i < m; i++) {
        int c, a, b;
        cin >> c >> a >> b;
        c--, a--, b--;

        g[a][c].pb(b);
        g[b][c].pb(a);
    
    }

    int curComp = 0;
    for(int i = 0; i < n; i++) 
        if(!used[i])
            dfs2(i, curComp++);
    
    map<pii, bool> edgeExist;
    for(int i = 0; i < n; i++) 
        for(int &j : g[i][0]) {

            if(edgeExist[{scc[i], scc[j]}])
                continue;

            if(scc[i] == scc[j]) {
                cout << -1 << endl;
                return;
            }

            edgeExist[{scc[i], scc[j]}] = 1;
            ng[scc[i]].push_back(scc[j]);
            ng[scc[j]].push_back(scc[i]);
        }

    for(int i = 0; i < curComp; i++)
        used[i] = false;

    int ans = 0;
    for(int i = 0; i < curComp; i++)
        if(!used[i]) {
            nc.clear();
            dfs(i);
            if(!dans) {
                cout << -1 << endl;
                return;
            }

            int a = 0, b = 0;
            for(int &x : nc) {
                if(!color[x])
                    a += comp[x].size();
                else
                    b += comp[x].size();
            }
            ans += max(a, b);
        }
    
    cout << ans << endl;
    
}

int32_t main() {
    FAST;
    int ct = 1;
    cin >> ct;
    while(ct--)
        solve();
    return 0;
}