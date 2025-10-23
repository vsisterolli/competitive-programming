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
const ll mod = 1e9 + 9, MAXN = 2e5 + 5;
typedef vector<int> vi;
typedef pair<int, pair<int, int>> piii;

int dp[1005][1005][15];
void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n), b(m);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < m; i++)
        cin >> b[i];
    
    sort(all(a));
    sort(all(b));
    
    memset(dp, 0, sizeof dp);
    
    dp[0][0][k] = 1;
    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= m; j++)
            for(int x = k; x >= 0; x--) {
                if(i + 1 <= n)
                    dp[i + 1][j][x] = (dp[i + 1][j][x] + dp[i][j][x])%mod;
                if(j + 1 <= m)
                    dp[i][j + 1][x] = (dp[i][j + 1][x] + dp[i][j][x])%mod;
                if(i + 1 <= n && j + 1 <= m)
                    dp[i + 1][j + 1][x] = (dp[i + 1][j + 1][x] - dp[i][j][x] + mod)%mod;
            
                if(x && a[i] > b[j])
                    dp[i + 1][j + 1][x - 1] = (dp[i + 1][j + 1][x - 1] + dp[i][j][x])%mod;
            }
            
    cout << dp[n][m][0] << endl;
}

int32_t main() {
    setIO("team");
    int ct = 1;
    // cin >> ct;
    while(ct--)
        solve();
    return 0;
}