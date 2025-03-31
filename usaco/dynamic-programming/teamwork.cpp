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

    vector<int> v(n), dp(n + 5);
    int mx[n + 5][k + 5];
    
    memset(mx, 0, sizeof dp);

    for(int i = 0; i < n; i++)
        cin >> v[i];

    for(int i = 0; i < n; i++) {
        mx[i][1] = v[i];
        for(int j = 2; j <= k && i - j + 1 >= 0; j++)
            mx[i][j] = max(v[i], mx[i - 1][j - 1]);
    }
    
    for(int i = n - 1; i >= 0; i--)
        for(int j = 1; j <= k && i + j <= n; j++) 
            dp[i] = max(dp[i], dp[i + j] + mx[i + j - 1][j] * j);
        
    cout << dp[0] << endl;
}

int32_t main() {
    setIO("teamwork");
    int ct = 1;
    // cin >> ct;
    while(ct--)
        solve();
    return 0;
}