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
    int n, k;
    cin >> n >> k;

    int dp[n][k + 5][5];
    memset(dp, 0, sizeof dp);

    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        char x;
        cin >> x;
        if(x == 'H')
            x = 0;
        else if(x == 'P')
            x = 1;
        else x = 2;
        v[i] = x;
    }

    dp[0][k][0] = (v[0] == 2); 
    dp[0][k][1] = (v[0] == 0); 
    dp[0][k][2] = (v[0] == 1); 
    
    int ans = max({dp[0][k][0], dp[0][k][1], dp[0][k][2]});
    for(int i = 1; i < n; i++)
        for(int j = k; j >= 0; j--) {
            dp[i][j][0] = dp[i - 1][j][0];
            dp[i][j][1] = dp[i - 1][j][1];
            dp[i][j][2] = dp[i - 1][j][2];
            if(j + 1 <= k) {
                dp[i][j][0] = max({dp[i][j][0], dp[i - 1][j + 1][2], dp[i - 1][j + 1][1]});
                dp[i][j][1] = max({dp[i][j][1], dp[i - 1][j + 1][0], dp[i - 1][j + 1][2]});
                dp[i][j][2] = max({dp[i][j][2], dp[i - 1][j + 1][0], dp[i - 1][j+ 1][1]});
            }

            dp[i][j][0] += (v[i] == 2);
            dp[i][j][1] += (v[i] == 0);
            dp[i][j][2] += (v[i] == 1);
            
            ans = max({dp[i][j][0], dp[i][j][1], dp[i][j][2]});
        }
    
    cout << ans << endl;
}

int32_t main() {
    setIO("hps");
    int ct = 1;
    // cin >> ct;
    while(ct--)
        solve();
    return 0;
}