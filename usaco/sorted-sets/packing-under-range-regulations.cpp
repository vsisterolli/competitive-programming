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

using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 


void solve() {
    int n;
    cin >> n;
    
    vector<pii> v(n);
    for(pii &i : v)
        cin >> i.f >> i.s;

    sort(all(v), [&](pii a, pii b) -> bool {
        if(a.s - a.f != b.s - b.f)
            return a.s - a.f < b.s - b.f;
        return a.f < b.f;
    });

    ordered_set puts;
    
    for(int i = 0; i < n; i++) {
        
        if(puts.find(v[i].f) == puts.end()) {
            puts.insert(v[i].f);
            continue;
        }

        int ini = v[i].f, mid, end = v[i].s, ans = v[i].s + 1;
        while(ini <= end) {
            mid = (ini + end)/2;

            if(puts.find(mid) == puts.end() || (puts.order_of_key(mid) - puts.order_of_key(v[i].f) != mid - v[i].f) ) {
                if(puts.find(mid) == puts.end())
                    ans = min(ans, mid);
                end = mid - 1;
            }
            else ini = mid + 1;
            
        }
        
        if(ans == v[i].s + 1) {
            cout << "No" << endl;
            return;
        }
        
        puts.insert(ans);
    }
    cout << "Yes" << endl;
    return;
}

int32_t main() {
    int ct = 1;
    cin >> ct;
    while(ct--)
        solve();
    return 0;
}