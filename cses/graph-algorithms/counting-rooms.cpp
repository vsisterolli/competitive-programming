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
    int n, m;
    cin >> n >> m;

    char mat[n][m];
    for(int i = 0; i < n; i++)
        for(char &j : mat[i])
            cin >> j;
        
    int ans = 0;
    int x[4] = {1, -1, 0, 0}, y[4] = {0, 0, 1, -1};

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) 
            if(mat[i][j] == '.') {
                ans++;
                queue<pii> q({{i, j}});
                while(!q.empty()) {
                    pii cur = q.front();
                    q.pop();
                    mat[cur.f][cur.s] = '#';
                    for(int k = 0; k < 4; k++) {
                        int ni = cur.f + x[k], nj = cur.s + y[k];
                        if(ni >= 0 && nj >= 0 && ni < n && nj < m && mat[ni][nj] == '.') {
                            mat[ni][nj] = '#';
                            q.push({ni, nj});
                        }
                    }
        
                }
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