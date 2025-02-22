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
const ll mod = 1e9 + 7, MAXN = 2e5 + 5;
typedef vector<int> vi;
typedef pair<int, pair<int, int>> piii;


void solve() {
    int n;
    cin >> n;

    vector<int> v(n), c(n);
    for(int &i : v)
        cin >> i;
    for(int &i : c)
        cin >> i;
    
    vector<ll> b[MAXN];
    for(int i = 0; i < n; i++)
        b[c[i]].pb(v[i]);
    for(int i = 0; i < MAXN; i++)
        for(int j = 1; j < b[i].size(); j++)
            b[i][j] += b[i][j - 1];

    int q;
    cin >> q;

    ll toSum = 0;
    vector<ll> toRmv(MAXN);
    
    while(q--) {
        int type, color;
        ll x;
        cin >> type >> color >> x;
        if(type == 1) {
            toSum += x;
            toRmv[color] += x;
        }
        else {
            int ini = 0, mid, end = b[color].size() - 1, ans = -1;
            while(ini <= end) {
                mid = (ini + end)/2;

                ll tot = toSum * (mid + 1) - (toRmv[color] * (mid + 1)) + b[color][mid];
                if(tot <= x) {
                    ans = max(ans, mid);
                    ini = mid + 1;
                }
                else end = mid - 1;
            }
            cout << ans + 1 << endl;
        }
    }
}

int32_t main() {
    FAST;
    int ct = 1;
    // cin >> ct;
    while(ct--)
        solve();
    return 0;
}