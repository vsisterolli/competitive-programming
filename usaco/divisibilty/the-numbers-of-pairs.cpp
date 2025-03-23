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
const ll mod = 1e9 + 7, MAXN = 2e7 + 5;
typedef vector<int> vi;
typedef pair<int, pair<int, int>> piii;

int factor[MAXN];

void sieve() {
    for(int i = 2; i < MAXN; i++)
        if(!factor[i])
            for(int j = i; j < MAXN; j += i)
                factor[j] = i;
}

void solve() {
    int c, d, x;
    cin >> c >> d >> x;

    long long ans = 0;
    for(int g = 1; g * g <= x; g++) {
        if( !(x % g) && !((x/g + d) % c) ) {
            int AB = ((x/g) + d)/c, cur = 0;
            while(AB > 1) {
                int p = factor[AB];
                while(AB % p == 0)
                    AB /= p;
                cur++;
            }
            ans += (1ll<<cur);
        }
        int pg = g;
        g = x/g;
        if(g > 0 && g > pg && !(x % g) && !((x/g + d) % c) ) {
            int AB = ((x/g) + d)/c, cur = 0;
            while(AB > 1) {
                int p = factor[AB];
                while(AB % p == 0)
                    AB /= p;
                cur++;
            }
            ans += (1ll<<cur);
        }
        g = pg;
    }

    
    cout << ans << endl;
}

int32_t main() {
    FAST;
    sieve();
    int ct = 1;
    cin >> ct;
    while(ct--)
        solve();
    return 0;
}