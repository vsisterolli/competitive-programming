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
#define int long long
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

    int m[n+1][n+1], mni[n*n+1], mxi[n*n+5], mnj[n*n+5], mxj[n*n+5];
    memset(mxi, 0, sizeof mxi);
    memset(mxj, 0, sizeof mxj);
    fill(mnj, mnj+n*n+5, n+1);
    fill(mni, mni+n*n+5, n+1);

    int diffc = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++) {
            cin >> m[i][j];
            if(!m[i][j])
                continue;
            if(mni[m[i][j]] == n + 1)
                diffc++;
            mni[m[i][j]] = min(mni[m[i][j]], i);
            mnj[m[i][j]] = min(mnj[m[i][j]], j);
        
            mxi[m[i][j]] = max(mxi[m[i][j]], i);
            mxj[m[i][j]] = max(mxj[m[i][j]], j);
        } 
    if(diffc == 1) {
        cout << n * n - 1 << endl;
        return 0;
    }
    
    int sum[n+5][n+5];
    memset(sum, 0, sizeof sum);

    for(int i = 1; i <= n * n; i++) {
        if(mni[i] == n + 1)
            continue;
    
        sum[mni[i]][mnj[i]]++;
        sum[mni[i]][mxj[i] + 1]--;
        sum[mxi[i] + 1][mnj[i]]--;
        sum[mxi[i] + 1][mxj[i] + 1]++;
    }

    int ans = n * n;
    vector<bool> poss(n * n + 1, 1);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++) {
            sum[i][j] += sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
            if(m[i][j] && sum[i][j] >= 2) {
                ans -= poss[m[i][j]];
                poss[m[i][j]] = 0;
            }
        }

    
    cout << ans << endl;
}

