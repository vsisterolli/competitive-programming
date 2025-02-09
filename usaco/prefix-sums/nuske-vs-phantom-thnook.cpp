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
const ll mod = 1e9 + 7, MAXN = 2e5 + 5;
typedef vector<int> vi;
typedef pair<int, pair<int, int>> piii;

void solve() {
    int nl, nc, q;
    cin >> nl >> nc >> q;

    char m[nl+1][nc+1];
    memset(m, '0', sizeof m);
    for(int i = 1; i <= nl; i++)
        for(int j = 1; j <= nc; j++) {
            cin >> m[i][j];
            m[i][j] -= '0';
        }

    int sum[nl+1][nc+1];
    memset(sum, 0, sizeof sum);

    for(int i = 1; i <= nl; i++)
        for(int j = 1; j <= nc; j++) {

            sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
                
            if(m[i][j] == 0)
                continue;
            

            int aux = m[i-1][j], aux2 = m[i][j-1];
            if(aux + aux2 == 0)
                sum[i][j]++;

            if(aux + aux2 == 2)
                sum[i][j]--;
        }
    
    int hsum[nl+1][nc+1], vsum[nl+1][nc+1];
    memset(hsum, 0, sizeof hsum);
    memset(vsum, 0, sizeof vsum);

    for(int i = 1; i <= nl; i++)
        for(int j = 1; j <= nc; j++) {
            hsum[i][j] += hsum[i][j-1];
            vsum[i][j] += vsum[i-1][j];
            if(m[i][j]) {
                vsum[i][j] += !m[i-1][j];
                hsum[i][j] += !m[i][j-1];
            }
        }

    while(q--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        int ans = m[x1][y1];
        ans += (hsum[x1][y2] - hsum[x1][y1]) + (vsum[x2][y1] - vsum[x1][y1]);
        cout << ans + (sum[x2][y2] - sum[x2][y1] - sum[x1][y2] + sum[x1][y1]) << endl;
    }
}

int32_t main() {
    int ct = 1;
    // cin >> ct;
    while(ct--)
        solve();
}