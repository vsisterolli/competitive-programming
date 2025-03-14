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

    int m2[n + 1][n + 1], m[n + 1][n + 1];
    memset(m2, 0, sizeof m2);
    memset(m, 0, sizeof m);

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> m[i][j];

    int ini = 0, mid, end = 1e9, ans = 1e9;
    while(ini <= end) {
        mid = (ini + end)/2;

        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++) {
                if(m[i][j] > mid)
                    m2[i][j] = -1;
                else m2[i][j] = 1;
            }

        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                m2[i][j] += m2[i - 1][j] + m2[i][j - 1] - m2[i -1][j - 1];
        
        bool deu = false;
        for(int i = 1; i + k - 1 <= n; i++)
            for(int j = 1; j + k - 1 <= n; j++) {
                int sum = m2[i + k - 1][j + k - 1] - m2[i + k - 1][j - 1] - m2[i - 1][j + k - 1] + m2[i - 1][j - 1];
                if(sum >= 0) 
                    deu  = true;
            }

        if(deu) {
            ans = min(ans, mid);
            end = mid - 1;
        }
        else ini = mid + 1;
    }

    cout << ans << endl;
}

int32_t main() {
    int ct = 1;
    // cin >> ct;
    while(ct--)
        solve();
    return 0;
}