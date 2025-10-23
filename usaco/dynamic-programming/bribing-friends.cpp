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
    int n, a, b;
    cin >> n >> a >> b;

    vector<array<int, 3>> f(n);
    for(auto &i : f) 
        cin >> i[1] >> i[2] >> i[0];
    
    sort(all(f));

    int dp[n + 1][a + b + 1];
    memset(dp, 0, sizeof dp); 

    int ans = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j <= a + b; j++) {
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
            
            auto [x, p, c] = f[i];

            int have = b - j;
            if(have >= x * c) 
                dp[i + 1][j + x * c] = max(dp[i + 1][j + x * c], dp[i][j] + p);

            else {
                if(have >= 0)
                    c -= have/x;

                if(max(b, j) + c <= a + b)
                    dp[i + 1][max(b, j) + c] = max(dp[i + 1][max(b, j) + c], dp[i][j] + p);
            }
                
            ans = max(ans, dp[i][j]);
        }

    for(int i = 0; i <= a + b; i++)
        ans = max(ans, dp[n][i]);

    cout << ans << endl;
}

int32_t main() {
    int ct = 1;
    // cin >> ct;
    while(ct--)
        solve();
    return 0;
}