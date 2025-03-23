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

void solve() {
    int n, m;
    cin >> n >> m;

    vi v(n);
    for(int &i : v) 
        cin >> i;
    

    vector<vi> lsegs(n + 1), rsegs(n + 1);
    vector<pii> segs(m);
    for(int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        segs[i] = {l, r};
        lsegs[r].push_back(l);
        rsegs[l].push_back(r);
    }

    vi ans(n + 1, -INF);
    vi rmv(n + 1, 0);

    ans[0] = 0;

    int mn = v[0];
    for(int i = 1; i < n; i++) {
        for(int &j : lsegs[i - 1]) 
            for(int k = j; k <= i - 1; k++) {
                rmv[k]++;
                mn = min(mn, v[k] - rmv[k]);
            }
        ans[i] = max(ans[i], v[i] - mn);
    }

    fill(all(rmv), 0);

    mn = v[n - 1];
    for(int i = n - 1; i >= 0; i--) {
        for(int &j : rsegs[i + 1]) 
            for(int k = i + 1; k <= j; k++) {
                rmv[k]++;
                mn = min(mn, v[k] - rmv[k]);
            }
        ans[i] = max(ans[i], v[i] - mn);
    }

    int mx = *max_element(all(ans));

    if(mx >= *max_element(all(v)) - *min_element(all(v))) {
        cout << mx << endl;
        for(int i = 0; i < n; i++) 
            if(ans[i] == mx) {
                vi apsegs;
                for(int j = 0; j < m; j++)
                    if(segs[j].f > i || segs[j].s < i)
                        apsegs.pb(j + 1);
                cout << apsegs.size() << endl;
                for(int &j : apsegs)
                    cout << j << " ";
                cout << endl;
                return;
            }
    }
    else {
        cout << *max_element(all(v)) - *min_element(all(v)) << endl;
        cout << 0 << endl;
    }
    
    
}

int32_t main() {
    int ct = 1;
    // cin >> ct;
    while(ct--)
        solve();
    return 0;
}