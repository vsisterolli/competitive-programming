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

    vector<array<int, 3>> v(n);
    for(auto &i : v)
        cin >> i[0] >> i[1] >> i[2];

    v.push_back({0, 0, 0});

    char c;
    double m;
    cin >> m;
    
    auto getDist = [&](int a, int b) -> double {
        return hypot(v[a][0] - v[b][0], v[a][1] - v[b][1]);
    };

    int mx = (1<<n);
    double ini = 1e-5, mid, end = 1e7, ans = 1e7;
    for(int z = 0; z <= 100; z++) {
        mid = (ini + end)/2.0;
        
        vector<double> s(n + 1);
        s[0] = mid;
        for(int i = 1; i <= n; i++)
            s[i] = s[i - 1] * m;
        vector<vector<double>> dp(mx, vector<double>(n+1, 1e5));
        dp[0][n] = 0;

        for(int i = 0; i < mx; i++) {
            for(int j = 0; j < n; j++) {

                int cnt = __builtin_popcount(i);

                dp[i][j] = 1e5;
                if( !(i & (1<<j)) )
                    continue;

                int prev = (i ^ (1<<j));
                for(int k = 0; k <= n; k++) {
                    if(( !(prev & (1<<k)) && (k != n) ))
                        continue;

                    dp[i][j] = min(dp[i][j], dp[prev][k] + getDist(j, k)/s[cnt - 1]);
                }

                if(dp[i][j] > v[j][2])
                    dp[i][j] = 1e5;
            }
        }
        
        bool deu = false;
        for(int i = 0; i < n; i++)
            if(dp[mx - 1][i] < 1e5) {
                deu = true;
                break;
            }
        
        if(deu) {
            ans = min(ans, mid);
            end = mid;
        }
        else ini = mid;
    }
    cout << fixed << setprecision(8) << ans << endl;
}

int32_t main() {
    int ct = 1;
    // cin >> ct;
    while(ct--)
        solve();
    return 0;
}