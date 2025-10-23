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

    int mat[n][n];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> mat[i][j];

    int mx = (1<<n);

    int val[mx];
    for(int i = 0; i < mx; i++) {
        val[i] = 0;
        for(int j = 0; j < n; j++)
            for(int k = j + 1; k < n; k++) {
                if(!((1<<j) & i) || !((1<<k) & i))
                    continue;

                val[i] += mat[j][k];
            }
    }

    int dp[mx];

    for(int i = 0; i < mx; i++) {
        dp[i] = val[i];

        vector<int> masks = {0};
    
        for(int j = i; j; j ^= (j & (-j))) {
            int sz = masks.size();
            for(int k = 0; k < sz; k++)
                masks.push_back(masks[k] | (j & (-j)));
        }

        for(int &j : masks)
            dp[i] = max(dp[i], dp[j] + dp[i ^ j]);
    
    }

    cout << dp[mx - 1] << endl;
}

int32_t main() {
    FAST;
    int ct = 1;
    // cin >> ct;
    while(ct--)
        solve();
    return 0;
}