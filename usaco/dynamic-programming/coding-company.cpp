#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <chrono>
#define pb push_back
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define endl '\n'
#define int long long
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
const ll mod = 1e9 + 7, MAXN = 2e5 + 5;
typedef vector<int> vi;
typedef pair<int, pair<int, int>> piii;

int dp[2][102][10002];

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> v(n + 1);
    for(int i = 1; i <= n; i++)
        cin >> v[i];
    sort(v.begin() + 1, v.end());
    
    dp[0][0][5000] = 1;
    int ans = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 0; j <= n; j++)
            for(int k = 0; k <= 10000; k++) {
                
                // 1 person only
                dp[i & 1][j][k] = dp[!(i & 1)][j][k];
                
                if(k + v[i] <= 10000 && j)
                    dp[i & 1][j][k] = (dp[i & 1][j][k] + dp[!(i & 1)][j - 1][k + v[i]])%mod;
                
                if(k >= v[i] && j + 1 <= n)
                    dp[i & 1][j][k] = (dp[i & 1][j][k] + dp[!(i & 1)][j + 1][k - v[i]] * (j + 1))%mod;
                
                // append without finishing
                dp[i & 1][j][k] = (dp[i & 1][j][k] + dp[!(i & 1)][j][k] * j)%mod;
                
                if(i == n && !j && k >= 5000 && k <= 5000 + x)
                    ans = (ans + dp[i & 1][j][k])%mod;
            }
    
    
    cout << ans << endl;
        
}

int32_t main() {
    FAST;
    int ct = 1;
    // cin >> ct;
    while(ct--)
        solve();
    return 0;
}