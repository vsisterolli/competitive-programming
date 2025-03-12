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

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];

    int ans = 0;
    for(int i = 31; i >= 0; i--) {
        pii rel[2] = {{0, 0}, {0, 0}};
    
        int cur = 0;
        for(int j = 0; j < n; j++) {
            cur ^= !!((1<<i) & v[j]);
            rel[cur].f = (rel[cur].f + j + 1)%mod;
            rel[cur].s = (rel[cur].s + 1)%mod;
        }
        
        cur = 0;
        for(int j = 0; j < n; j++) {

            int to_add = (rel[1].f * (1<<i))%mod;
            ans = (ans + to_add)%mod;

            bool has_bit = (1<<i) & v[j];

            if(has_bit) {
                rel[1].f = (rel[1].f - rel[1].s + mod)%mod;
                rel[0].f = (rel[0].f - rel[0].s + mod)%mod; 
                rel[1].s = (rel[1].s - 1 + mod)%mod;
                swap(rel[0], rel[1]);
            }
            else {
                rel[1].f = (rel[1].f - rel[1].s + mod)%mod;
                rel[0].f = (rel[0].f - rel[0].s + mod)%mod; 
                rel[0].s = (rel[0].s - 1 + mod)%mod;
            }


        }
    
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