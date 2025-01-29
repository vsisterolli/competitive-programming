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

    int v[n + 1], active[n + 1], aux[n];
    memset(active, 0, sizeof active);
    for(int i = 0; i < n; i++) {
        cin >> aux[i];
        v[aux[i]] = i;
    }

    int ans = 0;
    for(int i = 1; i <= n-1; i++) {
        ans += v[i] > v[i+1];
        active[i] = v[i] > v[i + 1];
     }

    while(q--) {
        int a, b;
        cin >> a >> b;

        a--, b--;
        swap(aux[a], aux[b]);
        a = aux[a];
        b = aux[b];
        if(a > b)
            swap(a, b);

        swap(v[a], v[b]);
        ans -= active[a] + active[b] + active[a-1];
        if(b - 1 != a) 
            ans += active[b-1];

        active[a] = v[a] > v[a + 1];
        if(b != n)
            active[b] = v[b] > v[b + 1];
        if(a != 1)
            active[a - 1] = v[a - 1] > v[a];
        active[b - 1] = v[b - 1] > v[b];
        
        ans += active[a] + active[b] + active[a-1];
        if(b-1 != a) 
            ans += active[b-1];

        cout << ans+1 << endl;
    }
    
}
