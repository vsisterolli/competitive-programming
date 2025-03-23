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

vector<int> g[MAXN], pai(MAXN);

int best = 1, bdist = 1;
void dfs(int u, int p = 1, int dist = 1) {
    if(dist > bdist)
        bdist = dist, best = u;

    for(int &i : g[u])
        if(i != p) {
            pai[i] = u;
            dfs(i, u, dist + 1);
        }
}

void solve() {
    int n;
    cin >> n;
    best = 1, bdist = 1;
    for(int i = 1; i <= n; i++) {
        pai[i] = 0;
        g[i].clear();
    }
    for(int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }
    dfs(1);
    bdist = 1;

    dfs(best, best);
    for(int i = 0; i < (bdist - 1)/2; i++)
        best = pai[best];

        vector<pii> ans;
    if(bdist & 1) 
        for(int i = 0; 2 * i <= bdist; i++)
            ans.push_back({best, i});
     
    else
        for(int i = bdist/2 - 1; i >= 0; i-=2) {
            ans.push_back({best, i});
            ans.push_back({pai[best], i});
        }
    
    cout << ans.size() << endl;
    for(pii &i : ans)
        cout << i.f << " " << i.s << endl;
}

int32_t main() {
    int ct = 1;
    cin >> ct;
    while(ct--)
        solve();
    return 0;
}