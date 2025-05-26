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

vector<int> g[MAXN], rg[MAXN];

vector<int> bfs(int start, int n) {
    vector<int> dist(n + 5, -1);
    queue<int> q({start});
    dist[start] = 0;

    while(!q.empty()) {
        int u = q.front();
        q.pop();

        for(int &nxt : g[u])
            if(dist[nxt] == -1) {
                dist[nxt] = dist[u] + 1;
                q.push(nxt);
            }
    }
    return dist;
}

void solve() {
    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        g[i].clear();
        rg[i].clear();
    }

    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        rg[b].push_back(a);
    }

    vector<int> d = bfs(1, n);
    int dp[n + 2][2];
    for(int i = 1; i <= n; i++) {
        dp[i][0] = d[i];
        dp[i][1] = d[i];
    }

    vector<int> order(n);
    iota(all(order), 1);
    sort(all(order), [&](int a, int b) -> bool {
        return d[a] > d[b];
    });

    for(int &u : order) {
        for(int &i : g[u]) {
            if(d[u] >= d[i])
                dp[u][0] = min(dp[u][0], dp[i][1]);
            else {
                dp[u][0] = min(dp[u][0], dp[i][0]);
                dp[u][1] = min(dp[u][1], dp[i][1]);
            }
        }
    }
    
    for(int i = 1; i <= n; i++)
        cout << min(dp[i][0], dp[i][1]) << " ";
    cout << endl;

}

int32_t main() {
    int ct = 1;
    cin >> ct;
    while(ct--)
        solve();
    return 0;
}