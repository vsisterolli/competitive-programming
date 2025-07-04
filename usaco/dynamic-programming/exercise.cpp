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
#define int long long
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
const ll mod = 1e9 + 7, MAXN = 7e5 + 5;
typedef vector<int> vi;
typedef pair<int, pair<int, int>> piii;

bool divisor[MAXN];
vector<int> primes;

void sieve() {
    for(int i = 2; i < MAXN; i++)
        if(!divisor[i]) {
            primes.push_back(i);
            for(int j = i + i; j < MAXN; j += i)
                divisor[j] = 1;
        }
}

void solve() {
    int n, m;
    cin >> n >> m;

    int N = primes.size();

    int dp[N + 5][n + 5];
    memset(dp, 0, sizeof dp);
    
    for (int i = 0; i <= n; i++) { dp[0][i] = 1; }

    for(int i = 1; i <= N; i++)
        for(int j = 0; j <= n; j++) {
            dp[i][j] = dp[i - 1][j];

            int p = primes[i - 1];
            while(p <= j) {
                dp[i][j] = (dp[i][j] + (dp[i - 1][j - p] * p)%m)%m;
                p = (p * primes[i - 1])%m;
            }

        }

    cout << dp[N][n] << endl;
}

int32_t main() {
    setIO("exercise");
    sieve();
    int ct = 1;
    // cin >> ct;
    while(ct--)
        solve();
    return 0;
}