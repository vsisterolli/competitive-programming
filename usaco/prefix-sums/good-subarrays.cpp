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

void solve() {
    int n;
    cin >> n;
    
    vector<char> v(n + 1);
    map<int, int> mapa;

    int s = 0, ans = 0;
    for(int i = 1; i <= n; i++) {
        cin >> v[i];
        v[i] -= '0';
        s += v[i];
        mapa[s - i]++;
    }

    s = 0, ans = mapa[0];
    for(int i = 1; i <= n; i++) {
        s += v[i];
        mapa[s - i]--;
        ans += mapa[s - i];
    }

    cout << ans << endl;

}

int32_t main() {
    int ct;
    cin >> ct;
    while(ct--) 
        solve();
    
}

