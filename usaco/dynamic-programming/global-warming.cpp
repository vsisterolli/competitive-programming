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

vector<int> getCompressed(vector<int> &v) {
    set<int> nums;
    for(int &i : v)
        nums.insert(i);
        
    vector<int> nv;
    for(int i : nums)
        nv.push_back(i);

    for(int &i : v)
        i = (lower_bound(all(nv), i) - nv.begin()) + 1;
    
    return nv;
}

ll seg[MAXN << 2];

void build(int u, int l, int r) {
    seg[u] = 0;
    if(l == r) 
        return;
    
    int mid = (l + r)/2;
    build(2 * u, l, mid);
    build(2 * u + 1, mid + 1, r);
    return;
}

void update(int u, int l, int r, int k, int x) {
    if(l > k or r < k)
        return;
    if(l == r) {
        seg[u] = max(seg[u], x);
        return;
    }
    int mid = (l+r)/2;
    update(2*u, l, mid, k, x);
    update(2*u+1, mid+1, r, k, x);
    seg[u] = max(seg[2*u], seg[2*u+1]);
    return;
}

ll query(int u, int l, int r, int lq, int rq) {
    if(l > rq || r < lq)
        return 0;
    if(l >= lq && r <= rq)
        return seg[u];

    int mid = (l+r) >> 1;
    return max(query(2 * u, l, mid, lq, rq), query(2 * u + 1, mid + 1, r, lq, rq));
}

void solve() {
    int n, x;
    cin >> n >> x;

    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];

    vector<int> oriv(all(v));
    vector<int> nv = getCompressed(v);

    vector<int> lis, f(n), c(n);
    for(int i = 0; i < n; i++) {
        auto aux = lower_bound(all(lis), v[i]);
        if(aux == lis.end()) {
            f[i] = (int)lis.size() + 1;
            lis.push_back(v[i]);
        }
        else {
            int pos = aux - lis.begin();
            f[i] = pos + 1;
            lis[pos] = v[i];
        }
    }
    lis.clear();

    for(int i = n - 1; i >= 0; i--) {
        auto aux = lower_bound(all(lis), -v[i]);
        if(aux == lis.end()) {
            c[i] = (int)lis.size() + 1;
            lis.push_back(-v[i]);
        }
        else {
            int pos = aux - lis.begin();
            c[i] = pos + 1;
            lis[pos] = -v[i];
        }
    }

    build(1, 1, n);
    int ans = 0;
    for(int i = 0; i < n; i++) {
        auto need = lower_bound(all(nv), oriv[i] + x);

        int val = 0;
        if(need != nv.begin()) {
            need--;
            val = query(1, 1, n, 1, (need - nv.begin()) + 1);
        }
        
        ans = max(ans, c[i] + val);
        update(1, 1, n, v[i], f[i]); 
    }
    
    cout << ans << endl;
    
}

int32_t main() {
    FAST;
    int ct = 1;
    // cin >> ct;
    while(ct--)
        solve();
    return 0;
}