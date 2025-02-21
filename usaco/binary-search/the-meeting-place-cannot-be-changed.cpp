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

    vector<double> x(n), v(n);
    for(double &i : x)
        cin >> i;
    for(double &i : v)
        cin >> i;

    const int factor = 1e6;

    int ini = 0, end = 1e15;
    double ans = 1e15;
    while(ini <= end) {
        double mid = 1.0 * (ini + end)/(2 * factor);

        double mn = 0.0, mx = 1e9;
        for(int i = 0; i < n; i++) {
            mx = min(mx, (double)1.0 * x[i] + 1.0 * v[i] * mid);
            mn = max(mn, (double)1.0 * x[i] - v[i] * mid);
        }

        if(mx >= mn) {
            ans = min(ans, mid);
            end = (ini + end)/2 - 1;
        }
        else    
            ini = (ini + end)/2 + 1;
        
    }
    cout << fixed << setprecision(10) << ans << endl;
}

int32_t main() {
    int ct = 1;
    // cin >> ct;
    while(ct--)
        solve();
    return 0;
}