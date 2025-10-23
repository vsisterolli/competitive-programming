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

void solve() {
    int n, p, k;
    cin >> n >> p >> k;
    vector<pii> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i].f;
        v[i].s = i;
    }
    
    vector<vector<int>> s(n, vector<int>(p));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < p; j++)
            cin >> s[i][j];
    sort(all(v), greater<pii>());        

    int mx = (1<<p);
    vector<vector<int>> dp(n + 1, vector<int>(mx, -1e18));
    dp[0][0] = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < mx; j++) {
            for(int k = 0; k < p; k++) {
                if((1<<k) & j)
                    continue;
            
                dp[i + 1][j | (1<<k)] = max(dp[i + 1][j | (1<<k)], dp[i][j] + s[v[i].s][k]);
            }
            int need = k - i + __builtin_popcount(j);
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + (need > 0) * v[i].f);
        }
    }
    cout << dp[n][mx - 1] << endl;
}

int32_t main() {
    int ct = 1;
    // cin >> ct;
    while(ct--)
        solve();
    return 0;
}