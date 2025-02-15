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
#define debug3(x, y, z) cerr << "DEBUG " << x << " " << y << " " << z<< endl
#define debug4(x, y, z, o) cerr << "DEBUG " << x << " " << y << " " << z<< " " << o << endl
#define all(x) x.begin(), x.end()
#define left esquerda
#define lb lower_bound
#define right direita
using namespace std;
void setIO(string s) {
ios_base::sync_with_stdio(0); cin.tie(0);
freopen((s+".in").c_str(),"r",stdin);
freopen((s+".out").c_str( ),"w",stdout);
}
typedef pair<ll, ll> pii;
typedef vector<vector<char>> mat;
typedef pair<int, string> pis;
const ll mod = 1e9 + 7, MAXN = 2e5 + 5;
typedef vector<int> vi;
typedef pair<int, pair<int, int>> piii;
using namespace __gnu_pbds;
template <class K, class V>
using ht =
    gp_hash_table<K, V, hash<K>, equal_to<K>, direct_mask_range_hashing<>,
                  linear_probe_fn<>,
                  hash_standard_resize_policy<hash_exponential_size_policy<>,
                                              hash_load_check_resize_trigger<>, true>>;

vector<int> factors[MAXN];

void get() {
    for(int i = 1; i < MAXN; i++)
        for(int j = i; j < MAXN; j+= i)
            factors[j].pb(i);
}

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for(int &i : a)
        cin >> i;
    sort(all(a));

    int l = -1, r = 0, tot = 0, ans = a[n - 1] + 1;
    vector<int> cont(m + 5);

    while(l + 1 < n) {
        
        if(l >= 0) {

            for(int &i : factors[a[l]]) {
                if(i > m)
                    break;
                if(cont[i] == 1) 
                    tot--;
                cont[i]--;
            }

        }
        l++;

        while(r < n && tot < m) {

            for(int &i : factors[a[r]]) {
                if(i > m)
                    break;
                if(!cont[i])
                    tot++;
                cont[i]++;
            }
            r++;

        }

        if(tot == m)
            ans = min(a[r - 1] - a[l], ans);

    }
    cout << (ans == a[n - 1] + 1 ? -1 : ans) << endl;

}

int32_t main() {
    // setIO("meetings");
    FAST;
    get();
    int ct = 1;    
    cin >> ct;
    while(ct--)
        solve();
}