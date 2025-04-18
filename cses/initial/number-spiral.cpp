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

ll solve(int x, int y) {
    ll ans = 0;
    swap(x, y); // i confused x and y btw xD

    if(x > y) {
        if(x & 1)
            ans = 1ll * x * x;
        else ans = 1ll * (x - 1) * (x - 1) + 1;

        ans += (x & 1 ? 1 - y : y - 1);
    }
    else {
        if(y & 1)
            ans = 1ll * (y - 1) * (y - 1) + 1;
        else ans = 1ll * y * y;
        
        ans += (y & 1 ? x - 1 : 1 - x);
    }
    
    return ans;
}

int32_t main() {
    int ct;
    cin >> ct;
    while(ct--) {
        int x, y;
        cin >> x >> y;
        cout << solve(x, y) << endl;
    }
}
