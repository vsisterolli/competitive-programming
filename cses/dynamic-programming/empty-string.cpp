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
const ll mod = 1e9 + 7, MAXN = 2005;
typedef vector<int> vi;
typedef pair<int, pair<int, int>> piii;

int fat[MAXN], inv[MAXN];

ll modExpo(ll a, ll p) {
    if(p == 0)
        return 1;
    if(p == 1)
        return a;

    ll mult = modExpo(a, p/2);
    if(p & 1)
        return (((mult * mult) % mod) * a) % mod;

    return (mult * mult) % mod;
}

void startComb() {
    fat[0] = fat[1] = inv[0] = inv[1] = 1;
    for(int i = 2; i < MAXN; i++) {
        fat[i] = (fat[i - 1] * i) % mod;
        inv[i] = modExpo(fat[i], mod - 2);
    }
}

ll c(int n, int k) {
    if(!k)
        return 1;
    if(n < k)
        return 0;
    int aux = (1ll * fat[n] * inv[n - k]) % mod;
    aux = (aux * inv[k]) % mod;
    return aux;
}

void solve() {
    string s;
    cin >> s;

    int n = s.size();

    int dp[n + 5][n + 5];
    memset(dp, 0, sizeof dp);
    for(int i = 0; i <= n+1; i++)
        dp[i + 1][i] = 1;

    for(int sz = 1; sz < n; sz++) 
        for(int i = 0; i + sz < n; i++)
            for(int k = 1; k <= sz; k+=2) {
                if((sz - k) & 1)
                    continue; 
                if(s[i] == s[i + k]) {
                    if(sz == 1)
                        dp[i][i + sz] = 1;
                    else 
                        dp[i][i + sz] = (((c((k + 1)/2 + (sz - k)/2, (sz - k)/2) * dp[i + 1][i + k - 1])%mod * dp[i + k + 1][i + sz] % mod) + dp[i][i + sz])%mod;
                }
            }


    
    cout << dp[0][n - 1] << endl;
}

int32_t main() {
    startComb();
    int ct = 1; 
    // cin >> ct;
    while(ct--)
        solve();
    return 0;
}