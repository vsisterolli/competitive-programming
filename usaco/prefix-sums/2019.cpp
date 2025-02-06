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
#define int long long
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
const ll mod = 2019, MAXN = 2e5 + 5;
typedef vector<int> vi;
typedef pair<int, pair<int, int>> piii;
// END HEADER

void solve() {
    string s;
    cin >> s;

    map<int, int> mapa;
    int cur = 0;

    reverse(s.begin(), s.end());

    int aux = 1, ans = 0;
    mapa[0] = 1;
    
    for(int i = 0; i < s.size(); i++) {
        cur = (cur + ((s[i] - '0') * aux))%mod;    
        aux = (aux * 10) % mod;
        ans += mapa[cur];
        mapa[cur]++;
    }

    cout << ans << endl;
}

int32_t main() {
    int ct = 1;
    while(ct--) 
        solve();   
}