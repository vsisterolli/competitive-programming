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

ll seg[4*MAXN], lazy[4*MAXN];

void unlazy(int u, int l, int r) {
    seg[u] += (r - l + 1) * lazy[u];
    if(l != r) {
        lazy[2*u] += lazy[u];
        lazy[2*u+1] += lazy[u];
    }
    lazy[u] = 0;
}

void update(int u, int l, int r, int lq, int rq, int x) {
    if(l > rq || r < lq)
        return;
    if(l >= lq && r <= rq) {
        lazy[u] += x;
        unlazy(u, l, r);
        return;
    }
    int mid = (l + r) / 2;
    update(2*u, l, mid, lq, rq, x);
    update(2*u+1, mid+1, r, lq, rq, x);
    seg[u] = seg[2*u] + seg[2*u+1];
    unlazy(u, l, r);
}

ll query(int u, int l, int r, int k) {
    unlazy(u, l, r);
    if(l > k || r < k)
        return 0;
    if(l == r && l == k)
        return seg[u];
    int mid = (l + r) / 2;
    return query(2*u, l, mid, k) + query(2*u+1, mid+1, r, k);
}

void build(int u, int l, int r, vector<int> &v) {
    lazy[u] = 0;
    if(l == r) {
        seg[u] = v[l];
        return;
    }
    
    int mid = (l + r)/2;
    build(2 * u, l, mid, v);
    build(2 * u + 1, mid+1, r, v);
    seg[u] = seg[2 * u] + seg[2 * u + 1];
    return;
}

void solve() {
    int n, q;
    cin >> n >> q;

    vector<int> v(n + 5), l(n + 5), r(n + 5);
    for(int i = 1; i <= n; i++)
        cin >> v[i];
    
    vector<vector<int>> g(n + 5);
    for(int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }


    vector<int> tour = {0};
    auto dfs = [&](int u, int p, int val, auto &dfs) -> void {
        val += v[u];
        l[u] = tour.size();
        tour.push_back(val);

        for(int &i : g[u])
            if(i != p)
                dfs(i, u, val, dfs);
        r[u] = (int)tour.size() - 1;
        return;
    };


    dfs(1, 1, 0, dfs);
    build(1, 1, n, tour);

    while(q--) {
        int t;
        cin >> t;
        
        if(t == 1) {
            int s, x;
            cin >> s >> x;
            update(1, 1, n, l[s], r[s], x-v[s]);
            v[s] = x;
        }
        else {
            int s;
            cin >> s;
            cout << query(1, 1, n, l[s]) << endl;
        }
    }

}

int32_t main() {
    int ct = 1;
    // cin >> ct;
    while(ct--)
        solve();
    return 0;
}