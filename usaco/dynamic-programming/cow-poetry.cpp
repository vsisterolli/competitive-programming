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

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<pii> v(n);
    for(pii &i : v)
        cin >> i.f >> i.s;

    vi dp(k + 5), ways(n + 5);

    dp[0] = 1;
    for(int i = 1; i <= k; i++)
        for(int j = 0; j < n; j++) 
            if(i - v[j].f >= 0)
                dp[i] = (dp[i] + dp[i - v[j].f])%mod;
    
    for(int i = 0; i < n; i++)
        if(v[i].f <= k) 
            ways[v[i].s] = (ways[v[i].s] + dp[k - v[i].f])%mod;
    
    vector<int> lines(27);
    for(int i = 0; i < m; i++) {
        char A;
        cin >> A;
        lines[A - 'A']++;
    }   

    int ans = 1;
    for(int i = 0; i < 26; i++) {
        if(!lines[i])
            continue;

        int kek = 0;
        for(int j = 1; j <= n; j++)
            kek = (kek + modExpo(ways[j], lines[i]))%mod;

        ans = (ans * kek)%mod;
    }
    
    cout << ans << endl;
}

int32_t main() {
    setIO("poetry");
    int ct = 1;
    // cin >> ct;
    while(ct--)
        solve();
    return 0;
}