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
 
void solve() {
    int n;
    cin >> n;
    vector<pii> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i].f >> v[i].s;
    }
    sort(all(v), [&](pii a, pii b) -> bool {
        if(a.f + a.s != b.f + b.s)
            return a.f + a.s < b.f + b.s;
        return a.s - a.f < b.s - b.f;
    });
 
    vector<int> lis;
    vector<vector<array<int, 3>>> ans;
 
    for(int i = 0; i < n; i++) {
        auto nx = lower_bound(all(lis), -(v[i].s - v[i].f));
        if(nx == lis.end()) {
            array<int, 3> aux ={v[i].f, v[i].s, lis.size() + 1}; 
            ans.push_back({aux});
            lis.push_back(-(v[i].s - v[i].f));
        }
        else {
            int pos = nx - lis.begin();
            array<int, 3> aux ={v[i].f, v[i].s, pos + 1}; 
            ans[pos].push_back(aux);
            lis[pos] = -(v[i].s - v[i].f);
        }
    }
 
    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); i++) {
        sort(all(ans[i]), [&](array<int, 3> a, array<int, 3> b) -> bool {
            return a[1] < b[1];
        });
        for(auto &j : ans[i])
            cout << j[0] << " " << j[1] << " " << j[2] << endl;
    }
    
}
 
int32_t main() {
    int ct = 1;
    // cin >> ct;
    while(ct--)
        solve();
    return 0;
}