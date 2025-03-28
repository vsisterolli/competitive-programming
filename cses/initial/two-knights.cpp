// HELPFUL HEADER ONLY
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <chrono>
#define pb push_back
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define endl '\n'
#define int long long
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


ll solve(int n) {

    if(n == 1) {
        cout << 0 << endl;
        return 0;
    }

    cout << 0 << endl << 6 << endl;
    ll prev = 6;

    for(int i = 3; i <= n; i++) {
        ll total = 1ll *  (i * i) * (i * i - 1)/2 - ((i - 1) * (i - 1)) * ((i - 1) * (i - 1) - 1)/2;
        total += prev;

        total -= 1LL * 8 * i - 16;
        cout << total << endl;

        prev = total;
    }

    return prev;
}

int32_t main() {
    int n;
    cin >> n;

    solve(n);
}
