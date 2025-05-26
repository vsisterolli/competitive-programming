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
const ll mod = 1e9 + 7, MAXN = 1e5 + 5;
typedef vector<int> vi;
typedef pair<int, pair<int, int>> piii;

ll dp[MAXN + 2][2];

int32_t main() {
    int n;
    cin >> n;

    vector<array<int, 3>> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i][0] >> v[i][1] >> v[i][2];
        v[i][2] = -v[i][2];
    }

    int m;
    cin >> m;
    v.resize(n + m);
    for(int i = n; i < n + m; i++) {
        cin >> v[i][0] >> v[i][1] >> v[i][2];
        v[i][0] = -v[i][0];
    }

    for(int j = 0; j < MAXN; j++)
        dp[j][0] = dp[j][1] = -LINF;

    ll ans = 0;
    sort(all(v), [&](array<int, 3> a, array<int, 3> b) -> bool {
        return a[1] > b[1];
    });
    
    dp[0][0] = 0;
    for(int i = 0; i < n + m; i++)
        for(int j = 0; j < MAXN; j++) {
            dp[j][!(i & 1)] = max(dp[j][!(i & 1)], dp[j][i & 1]);
            if(j + v[i][0] < MAXN && j + v[i][0] >= 0) {
                dp[j + v[i][0]][!(i & 1)] = max(dp[j + v[i][0]][!(i & 1)], dp[j][i & 1] + v[i][2]);
                ans = max(ans, dp[j + v[i][0]][!(i & 1)]);
            }
            ans = max({ans, dp[j][!(i & 1)], dp[j][i & 1]}); 
        }
    cout << ans << endl;
        
}