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

bool dp[505][505], dp2[505][505][505], ans[505];
int v[505], n, cnt = 0;


void calcdp(int i, int k, int sum) {

    if(!dp[i][k] || dp2[i][k][sum] || !i)
        return;

    dp2[i][k][sum] = 1;
    
    if(v[i] <= k && dp[i - 1][k - v[i]]) {
        cnt += !ans[sum + v[i]];
        ans[sum + v[i]] = 1;
        calcdp(i - 1, k - v[i], sum + v[i]);
        calcdp(i - 1, k - v[i], sum);
    }

    if(dp[i - 1][k])
        calcdp(i - 1, k, sum);

    return;
}

void solve() {
    FAST;
    int k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
        cin >> v[i];
    
    
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++) 
        for(int j = 0; j <= k; j++) {
            dp[i][j] |= dp[i - 1][j];
            if(v[i] <= j)
                dp[i][j] |= dp[i - 1][j - v[i]];
        }

    calcdp(n, k, 0);
    ans[0] = 1;
    cnt++;

    cout << cnt << endl;
    for(int i = 0; i <= k; i++)
        if(ans[i])
            cout << i << " ";
}

int32_t main() {
    int ct = 1;
    while(ct--)
        solve();
    return 0;
}