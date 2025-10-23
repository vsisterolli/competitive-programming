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

int dp[2][501][501];
char m[501][501];
int dist[501][501], pos[501][501];
vector<vector<pii>> cu(501), cd(501);

void solve() {
    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++) 
        for(int j = 0; j < n; j++) 
            cin >> m[i][j];

    memset(dist, -1, sizeof dist);
    queue<pii> q;
    q.push({0, 0});

    dist[0][0] = 0;
    while(!q.empty()) {
        pii cur = q.front();
        q.pop();

        pos[cur.f][cur.s] = cu[dist[cur.f][cur.s]].size();
        cu[dist[cur.f][cur.s]].push_back({cur.f, cur.s});

        if(dist[cur.f][cur.s] == n - 1)
            continue;
        
        if(cur.f + 1 < n && dist[cur.f + 1][cur.s] == -1) {
            q.push({cur.f + 1, cur.s});
            dist[cur.f + 1][cur.s] = dist[cur.f][cur.s] + 1;
        }
        if(cur.s + 1 < n && dist[cur.f][cur.s + 1] == -1) {
            q.push({cur.f, cur.s + 1});
            dist[cur.f][cur.s + 1] = dist[cur.f][cur.s] + 1;
        }
    }

    memset(dist, -1, sizeof dist);
    q.push({n - 1, n - 1});
    dist[n - 1][n - 1] = 0; 

    while(!q.empty()) {
        pii cur = q.front();
        q.pop();
        
        pos[cur.f][cur.s] = cd[dist[cur.f][cur.s]].size();
        cd[dist[cur.f][cur.s]].push_back({cur.f, cur.s});

        if(dist[cur.f][cur.s] == n - 1)
            continue;
        
        if(cur.f - 1 >= 0 && dist[cur.f - 1][cur.s] == -1) {
            q.push({cur.f - 1, cur.s});
            dist[cur.f - 1][cur.s] = dist[cur.f][cur.s] + 1;
        }
        if(cur.s - 1 >= 0 && dist[cur.f][cur.s - 1] == -1) {
            q.push({cur.f, cur.s - 1});
            dist[cur.f][cur.s - 1] = dist[cur.f][cur.s] + 1;
        }
    }

    sort(all(cd[n - 1]));
    sort(all(cu[n - 1]));
    for(int i = 0; i < cd[n - 1].size(); i++)
        pos[cd[n - 1][i].f][cd[n - 1][i].s] = i;
    memset(dp, 0, sizeof dp);

    dp[0][0][0] = 1;
    for(int i = 0; i < n - 1; i++) {
        memset(dp[!(i & 1)], 0, sizeof dp[!(i & 1)]);
        for(int j = 0; j < cu[i].size(); j++)
            for(int k = 0; k < cd[i].size(); k++) {
                if(m[cu[i][j].f][cu[i][j].s] != m[cd[i][k].f][cd[i][k].s]) {
                    dp[i & 1][j][k] = 0;
                    continue;
                }

                int viz1 = pos[cu[i][j].f + 1][cu[i][j].s];
                int viz2 = pos[cu[i][j].f][cu[i][j].s + 1];

                int viz3 = pos[cd[i][k].f - 1][cd[i][k].s];
                int viz4 = pos[cd[i][k].f][cd[i][k].s - 1];

                dp[!(i & 1)][viz1][viz3] = (dp[!(i & 1)][viz1][viz3] + dp[i & 1][j][k])%mod;   
                dp[!(i & 1)][viz1][viz4] = (dp[!(i & 1)][viz1][viz4] + dp[i & 1][j][k])%mod;   
                dp[!(i & 1)][viz2][viz3] = (dp[!(i & 1)][viz2][viz3] + dp[i & 1][j][k])%mod;   
                dp[!(i & 1)][viz2][viz4] = (dp[!(i & 1)][viz2][viz4] + dp[i & 1][j][k])%mod;   
            }
    }
    

    int ans = 0;
    for(int i = 0; i < n; i++) 
        ans = (ans + dp[((n - 1) & 1)][i][i])%mod   ;
    cout << ans << endl;

}

int32_t main() {
    int ct = 1;
    setIO("palpath");
    // cin >> ct;
    while(ct--)
        solve();
    return 0;
}