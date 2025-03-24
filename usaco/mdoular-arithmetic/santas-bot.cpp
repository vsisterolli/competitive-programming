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
const ll mod = 998244353, MAXN = 1e6 + 5;
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
    int n;
    cin >> n;

    vector<int> g[n], ap(MAXN);
    for(int i = 0; i < n; i++) {
        int k;
        cin >> k;
        for(int j = 0; j < k; j++) {
            int x;
            cin >> x;
            g[i].push_back(x);
            ap[x]++;
        }
    }

    int valid = 0;
    for(int i = 0; i < n; i++) {
        
        for(int &c : g[i]) {
            int k = g[i].size();

            int invN = modExpo(n, mod - 2);
            int invK = modExpo(k, mod - 2);

            int choosenChance = (invN * invN)%mod;
            choosenChance = (choosenChance * invK)%mod;

            valid = (valid + (choosenChance * ap[c])%mod)%mod;
        }

    }
    cout << valid%mod << endl;
}

int32_t main() {
    int ct = 1;
    // cin >> ct;
    while(ct--)
        solve();
    return 0;
}