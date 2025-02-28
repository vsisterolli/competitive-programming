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
    int n, l;
    cin >> n >> l;

    vector<pii> v(n);
    for(pii &i : v)
        cin >> i.f >> i.s;

    int ini = 0, end = 2e15;
    double ans = 2e15;
    while(ini <= end) {
        double mid = 1.0 * ((double)ini + end)/2e5;

        double cur = 0;
        for(pii &i : v) {
            double c = mid;
            double b = i.s;
            double a = 1.0 * sqrt((double)c * c - b * b);

            if( i.f - a <= cur )
                cur = max(cur, i.f + a);
        }

        int xd = (ini + end)/2;
        if(cur >= l) {
            end = xd - 1;
            ans = min(ans, mid);
        } else ini = xd + 1;

    }
    cout << fixed << setprecision(5) << ans << endl;
    
}

int32_t main() {
    int ct = 1;
    // cin >> ct;
    while(ct--)
        solve();
    return 0;
}