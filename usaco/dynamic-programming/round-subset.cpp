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

int dp[2][201][5001];
bool used[2][201][5001];

void solve() {
    int n, k;
    cin >> n >> k;

    vi d(n), c(n);
    for(int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        while(x % 2 == 0) {
            d[i]++;
            x >>= 1;
        }
        while(x % 5 == 0) {
            c[i]++;
            x /= 5;
        }
    }

    used[0][k][0] = 1;
    for(int i = 0; i < n; i++)
        for(int j = 0; j <= k; j++)
            for(int z = 0; z <= 5000; z++) {
                if(!used[i & 1][j][z])
                    continue;

                if(j) {
                    used[!(i & 1)][j - 1][z + c[i]] = 1;
                    dp[!(i & 1)][j - 1][z + c[i]] = max(dp[!(i & 1)][j - 1][z + c[i]], d[i] + dp[i & 1][j][z]);
                }
                used[!(i & 1)][j][z] = 1;
                dp[!(i & 1)][j][z] = max(dp[!(i & 1)][j][z], dp[i & 1][j][z]);
            }
    int ans = 0;
    for(int z = 0; z <= 5000; z++) 
        ans = max(ans, min(dp[n & 1][0][z], z));
    
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