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
    vector<int> p(n), b(m);
    vector<vector<int>> good(n);
    for(int i = 0; i < n; i++)
        cin >> p[i];
    for(int i = 0; i < m; i++) 
        cin >> b[i];

    int mx = (1<<m);
    for(int i = 0; i < mx; i++) {
        int sum = 0;
        for(int j = 0; j < m; j++)
            if((1<<j) & i)
                sum += b[j];

        for(int j = 0; j < n; j++)
            if(p[j] == sum) 
                good[j].push_back(i);
    }

    vector<int> dp(mx, -1);
    dp[0] = 0;
    for(int i = 0; i < mx; i++) {
        if(dp[i] < 0)
            continue;
            
        if(dp[i] == n) {
            cout << "YES" << endl;
            return;
        }
        for(int &j : good[dp[i]]) {
            if(j & i) continue;
            dp[j | i] = dp[i] + 1;
        }
    }
    cout << "NO" << endl;
}

int32_t main() {
    FAST;
    int ct = 1;
    // cin >> ct;
    while(ct--)
        solve();
    return 0;
}