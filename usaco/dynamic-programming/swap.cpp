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

int dp[31][31][31][901];

void solve() {
    string s;
    cin >> s;

    int k;
    cin >> k;

    int n = s.size();
    k = min(k, n * n);

    vector<int> K, E, Y;
    for(int i = 0; i < n; i++) {
        if(s[i] == 'K')
            K.push_back(i);
        if(s[i] == 'E')
            E.push_back(i);
        if(s[i] == 'Y')
            Y.push_back(i);
    }

    int x = K.size(), y = E.size(), z = Y.size();

    dp[0][0][0][k] = 1;
    for(int a = 0; a <= x; a++) 
        for(int b = 0; b <= y; b++)
            for(int c = 0; c <= z; c++)
                for(int sw = 0; sw <= k; sw++) {
                    if(a + 1 <= x) {
                        int pa = a;
                        pa += max(b, (int)(lower_bound(all(E), K[a]) - E.begin()));
                        pa += max(c, (int)(lower_bound(all(Y), K[a]) - Y.begin()));
                        
                        int dif = pa - (a + b + c);
                        if(dif <= sw)
                            dp[a + 1][b][c][sw - dif] += dp[a][b][c][sw];
                    }
                    if(b + 1 <= y) {
                        int pa = b;
                        pa += max(a, (int)(lower_bound(all(K), E[b]) - K.begin()));
                        pa += max(c, (int)(lower_bound(all(Y), E[b]) - Y.begin()));
                        
                        int dif = pa - (a + b + c);
                        if(dif <= sw)
                            dp[a][b + 1][c][sw - dif] += dp[a][b][c][sw];
                    }
                    if(c + 1 <= z) {
                        int pa = c;
                        pa += max(a, (int)(lower_bound(all(K), Y[c]) - K.begin()));
                        pa += max(b, (int)(lower_bound(all(E), Y[c]) - E.begin()));
                        
                        int dif = pa - (a + b + c);
                        if(dif <= sw)
                            dp[a][b][c + 1][sw - dif] += dp[a][b][c][sw];
                    }
                }

    int ans = 0;
    for(int i = 0; i <= k; i++)
        ans += dp[x][y][z][i];
    cout << ans << endl;

}

int32_t main() {
    FAST;
    int ct = 1;
    // cin >> ct;
    while(ct--)
        solve();
    return 0;
}