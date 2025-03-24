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
#define int unsigned long long
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

int modExpo(int a, int p) {
    if(p == 0)
        return 1;
    if(p == 1)
        return a;

    int mult = modExpo(a, p/2);
    if(p & 1)
        return (((mult * mult) % mod) * a) % mod;

    return (mult * mult) % mod;
}

void solve() {
    setIO("sumdiv");
    int a, b;
    cin >> a >> b;
    int rb = b;
    b %= (mod - 1);

    int ans = 1;
    for(int i = 2; i * i <= a; i++) {
        int qtd = 0;
        while(a % i == 0) {
            qtd++;
            a /= i;
        }
        
        if(qtd) {
            int sub = modExpo(i, (qtd * b)%(mod - 1));
            sub = (sub * i + mod - 1)%mod;

            ans = (ans * sub)%mod;
            ans = (ans * modExpo((i + mod - 1), mod - 2))%mod;
        }
    }

    if(a > 1 && ((a - 1) % mod != 0)) { 
        int sub = modExpo(a, b);
        sub = (sub * a + mod - 1)%mod;
        if(sub < 0)
            sub += mod;

        ans = (ans * sub)%mod;
        ans = (ans * modExpo(a - 1 + mod, mod - 2))%mod;
    }
    else if(a > 1) {
        ans = (ans * ((rb + 1) % mod)) % mod;
    }
    cout << ans << endl;
}

int32_t main() {
    int ct = 1;
    // cin >> ct;
    while(ct--)
        solve();
    return 0;
}