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
const ll mod = 1e9 + 7, MAXN = 2e5 + 5;
typedef vector<int> vi;
typedef pair<int, pair<int, int>> piii;

void solve() {
    int n, x;
    cin >> n >> x;

    vector<int> h(n), s(n);
    for(int &i : h)
        cin >> i;
    for(int &i : s)
        cin >> i;

    vector<vector<int>> dp(n + 5, vector<int>(x + 5, 0));

    int ans = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 0; j <= x; j++) {
            dp[i][j] = dp[i - 1][j];
            if(h[i - 1] + j <= x)
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j + h[i - 1]] + s[i - 1]);

            ans = max(ans, dp[i][j]);
        }
    cout << ans << endl;
}

int32_t main() {
    int ct = 1;
    while(ct--)
        solve();
    return 0;
}