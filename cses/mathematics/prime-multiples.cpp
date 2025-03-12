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
const ll mod = 998244353, MAXN = 2e5 + 5;
typedef vector<int> vi;
typedef pair<int, pair<int, int>> piii;

int n, k;
vector<int> primes;
bool used[1048580];
int ans = 0;

void calc(int tot = 1, int mask = 0) {
    if(used[mask])
        return;
    used[mask] = 1;

    if(tot != 1) {
        if(__builtin_popcountll(mask) & 1)
            ans += n/tot;
        else 
            ans -= n/tot;
    }

    for(int i = 0; i < k; i++) {

        int to_skip = n/tot;
        if(primes[i] > to_skip)
            continue;

        if( (1<<i) & mask )
            continue;
    
        calc(tot * primes[i], mask | (1<<i));
    }

}

void solve() {
    cin >> n >> k;
    primes.assign(k, 0);
    for(int &i : primes)
        cin >> i;
    calc(1, 0);
    cout << ans << endl;
}

int32_t main() {
    FAST;
    int ct = 1;
    // cin >> ct;
    while(ct--)
        solve();
    return 0;
}