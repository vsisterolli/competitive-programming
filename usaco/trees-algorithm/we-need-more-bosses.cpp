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
const ll mod = 1e9 + 7, MAXN = 3e5 + 5;
typedef vector<int> vi;
typedef pair<int, pair<int, int>> piii;

int ans = 0;
vi lans(MAXN), used(MAXN), dp(MAXN), h(MAXN);
vi g[MAXN];

void dfs(int u, int p = 0) {
    used[u] = 1;

    vi sons;
    for(int &i : g[u]) {
        if(i == p)
            continue;
        if(!used[i]) {
            h[i] = h[u] + 1;
            dfs(i, u);
            lans[u] = max(lans[u], lans[i]);
            dp[u] += dp[i];
            sons.pb(lans[i]);
        }
        else {
            if(h[i] > h[u])
                dp[u]--;
            else
                dp[u]++;
        }
    }

    sort(all(sons), greater<int>());
    if(!dp[u] && h[u])
        lans[u]++;
    
    int cur = 0;
    for(int i = 0; i < sons.size() && i < 2; i++)
        cur += sons[i];

    ans = max({ans, lans[u], cur});
}

void solve() {
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].pb(b);
        g[b].pb(a);
    }

    dfs(0);
    cout << ans << endl;
}

int32_t main() {
    int ct = 1;
    // cin >> ct;
    while(ct--)
        solve();
    return 0;
}