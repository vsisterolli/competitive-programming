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
const ll mod = 998244353, MAXN = 5005;
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

int dp[5005][5005], v[5005], n;

int calcDp(int i, int j) {
    if(i == n)
        return (2 * j == n);

    int &ans = dp[i][j];
    if(ans != -1)
        return ans;

    int x = 1, ci = i;
    while(ci + 1 < n && v[ci + 1] == v[ci]) {
        x++;
        ci++;
    }   

    int pos = max(0ll, j - 1 + (2 * j == n) - (i - j));
    if(x > pos + 1)
        return ans = 0;

    ans = (calcDp(ci + 1, j + 1) * c(pos, x - 1))%mod;
    ans = (ans + (calcDp(ci + 1, j) *c(pos, x))%mod)%mod;

    return ans;
}

void solve() {
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> v[i];
    reverse(v, v + n);
    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= n; j++)
            dp[i][j] = dp[i][j]= -1;

    cout << calcDp(0, 0) << endl;
}

int32_t main() {
    startComb();
    int ct = 1;
    cin >> ct;
    while(ct--)
        solve();
    return 0;
}