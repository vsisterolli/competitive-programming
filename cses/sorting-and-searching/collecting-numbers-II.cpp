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
    int n, q;
    cin >> n >> q;

    vector<int> v(n), pos(n + 1);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
        pos[v[i]] = i;
    }

    int ans = 0;
    vector<int> contributing(n+1);
    for(int i = 2; i <= n; i++) {
        contributing[i] = pos[i] < pos[i-1];
        ans += contributing[i];
    }

    while(q--) {
        
        int a, b;
        cin >> a >> b;
        
        a--, b--;
        swap(v[a], v[b]);
        a = v[a];
        b = v[b];

        set<int> s;
        if(a < n)
            s.insert(a + 1);
        if(b < n)
            s.insert(b + 1);
        s.insert(a); s.insert(b);

        for(auto i : s)
            ans -= contributing[i];

        swap(pos[a], pos[b]);

        for(auto i : s) {
            contributing[i] = pos[i] < pos[i-1];
            ans += contributing[i];
        }

        cout << ans + 1 << endl;
    }
    
}
