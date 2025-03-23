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
const ll mod = 1e9 + 7, MAXN = 1e5 + 5;
typedef vector<int> vi;
typedef pair<int, pair<int, int>> piii;

vi g[MAXN];
int pai[MAXN], black[MAXN];

void dfs(int u) {
    for(int &i : g[u])
        if(i != pai[u]) {
            pai[i] = u;
            dfs(i);
        }
}

int count(int u) {
    int tot = 1;
    for(int &i : g[u])
        if(i != pai[u] && !black[i])
            tot += count(i);
    return tot;
}

void solve() {
    int n;
    cin >> n;

    for(int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }

    pai[1] = 1;
    dfs(1);

    vector<int> path = {};
    
    int u = n;
    while(u != 1) {
        path.push_back(u);
        u = pai[u];
    }
    path.push_back(1);
    reverse(all(path));

    int l = 1, r = path.size() - 2;
    black[path[r + 1]] = 1;
    while(l <= r) {
        l++;
        if(l <= r) {
            black[path[r]] = 1;
            r--;
        }
    }

    int cnt = count(1);
    if(cnt > n/2) 
        cout << "Fennec" << endl;
    else cout << "Snuke" << endl;
}

int32_t main() {
    int ct = 1;
    // cin >> ct;
    while(ct--)
        solve();
    return 0;
}