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
    int n, k;
    cin >> n >> k;

    vi sums;
    for(int i = 2; i <= n; i++) {
        cout << "and 1 " << i << endl;
        cout.flush();

        int nd;
        cin >> nd;

        cout << "or 1 " << i << endl;
        cout.flush();
        
        int ou;
        cin >> ou;

        int xr = ou - nd;
        int sum = xr + 2 * nd;
        sums.pb(sum);
    }

    cout << "and 2 3" << endl;
    int nd;
    cin >> nd;
    cout.flush();

    cout << "or 2 3" << endl;
    int ou;
    cin >> ou;
    cout.flush();

    int xr = ou - nd;
    int sum = xr + 2 * nd;

    int a1 = (sums[0] + sums[1] - sum)/2;
    vi ans;
    ans.pb(a1);

    for(int &i : sums)
        ans.pb(i - a1);
    sort(all(ans));

    cout << "finish " << ans[k - 1]  << endl;
    cout.flush();

}

int32_t main() {
    int ct = 1;
    // cin >> ct;
    while(ct--)
        solve();
    return 0;
}