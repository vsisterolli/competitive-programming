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
const ll mod = 1e9 + 7, MAXN = 2e5 + 5;
typedef vector<int> vi;
typedef pair<int, pair<int, int>> piii;
// END HEADER


int32_t main() {

    setIO("art");
    int n;
    cin >> n;

    char m[n][n];

    vector<int> ans(10, 0), happens(10, 0);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) {
            cin >> m[i][j];
            happens[m[i][j] - '0'] = ans[m[i][j] - '0'] = 1;
        }

    for(int i = 1; i <= 9; i++) {
        if(!happens[i])
            continue;

        for(int j = i + 1; j <= 9; j++) {
            if(!happens[j])
                continue;

            int li = n, ri = -1, ui = n, bi = -1;
            int lj = n, rj = -1, uj = n, bj = -1;

            for(int k1 = 0; k1 < n; k1++)
                for(int k2 = 0; k2 < n; k2++) {

                    if(m[k1][k2] == i + '0') {
                        li = min(li, k2);
                        ri = max(ri, k2);
                        ui = min(ui, k1);
                        bi = max(ui, k1);
                    }

                    if(m[k1][k2] == j + '0') {
                        lj = min(lj, k2);
                        rj = max(rj, k2);
                        uj = min(uj, k1);
                        bj = max(uj, k1);
                    }

                }
            
            
            for(int k1 = max(ui, uj); k1 <= min(bi, bj); k1++)
                for(int k2 = max(li, lj); k2 <= min(ri, rj); k2++) {
                    
                    if(m[k1][k2] == i + '0')
                        ans[i] = 0;
                    if(m[k1][k2] == j + '0')
                        ans[j] = 0;

                }
    
        }
    }

    int xd = 0;
    for(int i = 1; i <= 9; i++) 
        xd += ans[i];
    
    cout << xd << endl;
}

