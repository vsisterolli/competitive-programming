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
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();

    int dp[n + 1][m + 1];
    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= m; j++)
            dp[i][j] = 1e9;

    // i + 1, j + 1 + (s[i] == t[j]);
    // i + 1, j

    int ans = 1e9;
    dp[0][0] = 0;
    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= m; j++) {
            if(i == n) {
                dp[i][j] += (m - j);
                ans = min(ans, dp[i][j]);
                continue;
            } 
            if(j == m) {
                dp[i][j] += (n - i);
                ans = min(ans, dp[i][j]);
                continue;
            }
            dp[i][j + 1] = min(dp[i][j] + 1, dp[i][j + 1]);
            dp[i + 1][j] = min(dp[i][j] + 1, dp[i + 1][j]);
            dp[i + 1][j + 1] = min(dp[i][j] + !(s[i] == t[j]), dp[i + 1][j + 1]);
        }

    cout << ans << endl;
}

int32_t main() {
    int ct = 1;
    // cin >> ct;
    while(ct--)
        solve();
    return 0;
}