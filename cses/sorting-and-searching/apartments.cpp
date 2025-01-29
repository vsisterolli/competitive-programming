// HELPFUL HEADER ONLY
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
#define debug(x) cout << "DEBUG " << x << endl
#define debug2(x, y) cout << "DEBUG " << x << " " << y << endl
#define debug3(x, y, z) cout << "DEBUG " << x << " " << y << " " << z<< endl
#define debug4(x, y, z, o) cout << "DEBUG " << x << " " << y << " " << z<< " " << o << endl
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
const ll mod = 998244353, MAXN = 2e5 + 5;
typedef vector<int> vi;
typedef pair<int, pair<int, int>> piii;
// END HEADER

int32_t main() {
    FAST;
    int n, m, k;
    cin >> n >> m >> k;

    multiset<int> s;
    vector<int> v(n);
    for(int &i : v)
        cin >> i;
    for(int i = 0; i < m; i++) {
        int x;
        cin >> x;
        s.insert(x);
    }
    sort(v.begin(), v.end());

    int ans = 0;
    for(int i = 0; i < n; i++) {
        auto lb = s.lower_bound(v[i] - k);
        if(lb != s.end() && *lb - v[i] <= k) {
            ans++;
            s.erase(lb);
        }
    }
    cout << ans << endl;

}
