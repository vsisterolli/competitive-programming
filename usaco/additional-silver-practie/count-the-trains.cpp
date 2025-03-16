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

int seg[MAXN<<2];

void update(int u, int l, int r, int p, int x) {
    if(l > p || r < p)
        return;
    
    if(l == r && p == l) {
        seg[u] = x;
        return;
    }
    
    int mid = (l + r)>>1;
    update(2 * u, l, mid, p, x);
    update(2*u + 1, mid + 1, r, p, x);
    seg[u] = min(seg[2*u], seg[2*u + 1]);
    return;
}

int query(int u, int l, int r, int lq, int rq) {
    if(l > rq || r < lq)
        return LINF;

    if(l >= lq && r <= rq)
        return seg[u];
    
    int mid = (l + r)>>1;
    return min(query(2*u, l, mid, lq, rq), query(2*u + 1, mid + 1, r, lq, rq));
}

void solve() {
    int n, q;
    cin >> n >> q;

    for(int i = 1; i <= 4 * n; i++)
        seg[i] = 0;

    vector<int> v(n + 1);
    for(int i = 1; i <= n; i++)
        cin >> v[i];

    vector<pii> querys(q); vi ans(q);
    for(pii &i : querys) {
        cin >> i.f >> i.s;
        v[i.f] -= i.s;
    }

    for(int i = 1; i <= n; i++) 
        update(1, 1, n, i, v[i]);
    
    int curans = 1;
    for(int i = 2; i <= n; i++) 
        if(v[i] < query(1, 1, n, 1, i - 1))
            curans++;

    for(int &i : ans)
        cout << i << " ";
    cout << endl;

}

int32_t main() {
    int ct = 1;
    cin >> ct;
    while(ct--)
        solve();
    return 0;
}
