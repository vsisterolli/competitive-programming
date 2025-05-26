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

int32_t main() {
    int n;
    cin >> n;
    vector<int> v(n);

    int mn = 1000;
    for(int i = 0; i < n; i++) {
        cin >> v[i];
        mn = min(mn, v[i]);
    }
    // if(n == 1) {
    //     cout << v[0] + 1 << endl;
    //     return;
    // }

    int ans = 0;
    
    int dp[n][1005];
    memset(dp, 0, sizeof dp);
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= v[i] - mn; j++) {
            if(!i)
                dp[i][j] = j;
            if(i == n - 1) {
                dp[i][j] = dp[i - 1][j];
                ans += dp[i][j];
            }
            else dp[i][j] = (j ? dp[i][j - 1] : 0) + dp[i - 1][v[i] - mn - j];
        }
    }

    for(int rmv = mn - 1; rmv >= 0; rmv--) {
        for(int i = 1; i < n; i++)
            dp[i][v[i] - [rmv]]

    }

}