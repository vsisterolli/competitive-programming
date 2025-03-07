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

int dfs(int u, int p, vector<vector<int>> &g, vector<int> &sz, vector<int> &h) {
    sz[u] = 1;
    for(int &i : g[u])
        if(i != p) {
            h[i] = h[u] + 1;
            sz[u] += dfs(i, u, g, sz, h); 
        }
    return sz[u];
}

int solve(int u, int p, int curAns, int n, vector<vi> &g, vi &sz, vi &ans) {
    ans[u] = curAns;
    for(int &i : g[u])
        if(i != p) 
            solve(i, u, curAns + n - 2 * sz[i], n, g, sz, ans);
    return sz[u];
}

int32_t main() {
    int n;
    cin >> n;

    vector<vector<int>> g(n+1);
    vector<int> sz(n + 1), h(n + 1), ans(n + 1);
    for(int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }

    dfs(1, 1, g, sz, h);

    int iniAns = 0;
    for(int i = 1; i <= n; i++)
        iniAns += h[i];
    
    solve(1, 1, iniAns, n, g, sz, ans);
    for(int i = 1; i <= n; i++)
        cout << ans[i] << " ";
    cout << endl;
}