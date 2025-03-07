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

int dp[MAXN], used[MAXN], h[MAXN];
vi g[MAXN];

void createTree(int u) {
    used[u] = 1;
    for(int &i : g[u]) {
        if(!used[i]) {
            debug2(u+1, i+1);
            h[i] = h[u] + 1;
            createTree(i);
            dp[u] += dp[i];
        }
        else if(abs(h[u] - h[i]) > 1) {
            if(h[i] > h[u])
                dp[u]--;
            if(h[i] < h[u])
                dp[u]++;
        }
    }
    
    if(!dp[u] && h[u]) {
        cout << 0 << endl;
        exit(0);
    }
}

void solve() {
    int n, m;
    cin >> n >> m;

    vector<array<int, 2>> edges;
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].pb(b);
        g[b].pb(a);
        edges.pb({a, b});
    }

    
    createTree(0);
    for(auto &i : edges) {
        sort(i.begin(), i.end(), [&](int a, int b) -> bool {
            return h[a] < h[b];
        });

        if(h[i[1]] - h[i[0]] == 1)
            cout << i[0] + 1 << " " << i[1] + 1 << endl;
        else
            cout << i[1] + 1 << " " << i[0] + 1 << endl;

    }
}

int32_t main() {
    int ct = 1;
    // cin >> ct;
    while(ct--)
        solve();
    return 0;
}