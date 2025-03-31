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
    int t, a, b;
    cin >> t >> a >> b;

    bool dp[2][t + 5];
    int ans = 0;
    memset(dp, 0, sizeof dp);

    dp[0][0] = 1;
    for(int i = 1; i <= t; i++) {
        if(i - a >= 0)
            dp[0][i] |= dp[0][i - a];
        if(i - b >= 0)
            dp[0][i] |= dp[0][i - b];
        
        dp[1][i/2] |= dp[0][i];

        if(dp[0][i]) 
            ans = max(ans, i);
    }
    
    for(int i = 0; i <= t; i++) {
        if(i - a >= 0)
            dp[1][i] |= dp[1][i - a];
        if(i - b >= 0)
            dp[1][i] |= dp[1][i - b];
        
        if(dp[1][i])
            ans = max(ans, i);
    }

    cout << ans << endl;
}

int32_t main() {
    setIO("feast");
    int ct = 1;
    while(ct--)
        solve();
    return 0;
}