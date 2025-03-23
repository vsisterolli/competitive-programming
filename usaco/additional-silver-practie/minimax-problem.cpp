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
    int n, m;
    cin >> n >> m;

    int v[n][m];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> v[i][j];

    int ini = 0, mid, end = 1e9, ans = 0, ansl = 1, ansr = 1;
    while(ini <= end) {
            
        mid = (ini + end)/2;
        vector<int> have(256);

        for(int i = 0; i < n; i++) {
            int value = 0;
            for(int j = 0; j < m; j++) 
                if(v[i][j] >= mid)
                    value |= (1<<j);

            have[value] = i;
        }
        
        for(int i = 0; i < n; i++) {
            int value = 0;
            for(int j = 0; j < m; j++) 
                if(v[i][j] >= mid)
                    value |= (1<<j);
            
            int good = -1;
            for(int j = 0; j < 256; j++)
                if(have[j] && (value | j) == ((1<<m) - 1)) {
                    good = have[j];
                    break;
                }
            
            if(good != -1) {
                if(ans < mid) {
                    ans = mid;
                    ansl = i + 1;
                    ansr = good + 1;
                }
                ini = mid + 1;
                break;
            }
            else if(i == n - 1)
                end = mid - 1;
        }
    }
    cout << ansl << " " << ansr << endl;

}

int32_t main() {
    FAST;
    int ct = 1;
    // cin >> ct;
    while(ct--)
        solve();
    return 0;
}