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

ll modExpo(ll a, ll p, int x = 0) {
    if(p == 0)
        return 1;
    if(p == 1)
        return a;
 
    ll mult = modExpo(a, p/2, x);
    if(p & 1)
        return (((mult * mult) % (mod - x)) * a) % (mod - x);
 
    return (mult * mult) % (mod - x);
}

void solve() {
    int n;
    cin >> n;

    int sum = 1, amt = 1, amt2 = 1, prod = 1;
    vector<pii> factors;
    for(int i = 0; i < n; i++) {
        int x, k;
        cin >> x >> k;
        factors.push_back({x, k});

        sum = ((modExpo(x, k + 1) + mod - 1) * sum)%mod;
        sum = (sum * modExpo(x + mod - 1, mod - 2))%mod;
        amt = ((k + 1) * amt)%mod;

        int total = ((k + 1) * k)/2;
        
        int qtMultiplied = modExpo(modExpo(x, total), amt2);

        /*
            Suppose k = 3, then there is 4 possibilities of having x
            having x^0, x^1, x^2 and x^3
            So, we will take prod[i - 1] and consider 4 sets
            one of the sets will be just prod[i - 1]
            the other set will be prod[i - 1] with all of the numbers having x
            the other will be prod[i -1] with all the numbers having x^1 and so on...
        */
        prod = (modExpo(prod, k + 1) * qtMultiplied)%mod;

        amt2 = ((k + 1) * amt2) % (mod - 1);
        
    }  

    cout << amt << " " << sum << " " << prod << endl;
}

int32_t main() {
    int ct = 1;
    // cin >> ct;
    while(ct--)
        solve();
    return 0;
}