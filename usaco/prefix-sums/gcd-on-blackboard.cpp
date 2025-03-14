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
#define int long long
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
// END HEADER


int32_t main() {
    int n;
    cin >> n;

    vector<int> v(n), l(n), r(n);
    for(int &i : v)
        cin >> i;
    
    for(int i = 0; i < n; i++) {
        l[i] = v[i];
        if(i)
            l[i] = __gcd(l[i], l[i-1]);
    }

    for(int i = n - 1; i >= 0; i--) {
        r[i] = v[i];
        if(i + 1 < n)
            r[i] = __gcd(r[i], r[i + 1]);
    }

    int ans = r[1];
    for(int i = 1; i < n; i++) {
        int aux = l[i - 1];
        if(i + 1 < n)
            aux = __gcd(aux, r[i + 1]);
        
        ans = max(ans, aux);
    }
    cout << ans << endl;

    
    
}

