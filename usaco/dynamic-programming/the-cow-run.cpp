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
    int n;
    cin >> n;
    
    vector<int> l, r;

    r.push_back(0);    
    l.push_back(0);

    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;   

        if(x > 0)
            r.push_back(x);
        else l.push_back(x);
    }

    sort(all(r));
    sort(all(l), greater<int>());
    
    n = l.size();
    int m = r.size();

    int dp[n + 1][m + 1][2];
    memset(dp, 0, sizeof dp);
    
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) {
            if(i == 0 && j == 0)
                continue;

            dp[i][j][0] = dp[i][j][1] = 1e18;
            if(i) {
                dp[i][j][0] = dp[i - 1][j][0] + abs(l[i] - l[i - 1]) * (n + m - 1 - i - j);
                dp[i][j][0] = min(dp[i][j][0], dp[i - 1][j][1] + abs(l[i] - r[j]) * (n + m - 1 - i - j));
            }
            if(j) {
                dp[i][j][1] = dp[i][j - 1][0] + abs(r[j] - l[i]) * (n + m - 1 - i - j);
                dp[i][j][1] = min(dp[i][j][1], dp[i][j - 1][1]  + abs(r[j] - r[j - 1]) * (n + m - 1 - i - j));
            }

        }

    cout << min(dp[n - 1][m - 1][0], dp[n - 1][m - 1][1]) << endl;
}

int32_t main() {
    setIO("cowrun");
    int ct = 1;
    // cin >> ct;
    while(ct--)
        solve();
    return 0;
}