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
    int n;
    cin >> n;
    vector<int> v(n), ap(n), on(n + 1);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
        ap[v[i]] = i;
    }
    if(n == 1) {
        cout << 1 << endl;
        return;
    }
    
    int ans = 1;

    int l = ap[0], r = ap[0], cur = 1, expansion = 1, mex = 1;
    while(r - l + 1 < n) {
        // debug4(cur, l, r, expansion);
        // debug(ans);

        int newL = l;
        while(newL > ap[cur]) {
            int canExpand = expansion - (l - newL);
            if(canExpand >= 0) {
                // debug2("EXPANDIU", min(n - r - 1, canExpand + (l != newL)));
                ans += min(n - r - 1, canExpand) + 1;
            }
            newL--;
            on[v[newL]] = 1;
        }
        l = newL;
    
        int newR = r;
        while(newR < ap[cur]) {
            int canExpand = expansion - (newR - r);
            if(canExpand >= 0) {
                // debug2("EXPANDIU", min(l, canExpand + (r != newR)));
                ans += min(l, canExpand) + 1;
            }
            newR++;
            on[v[newR]] = 1;
        }
        r = newR;

        while(on[mex])
            mex++;
        while(on[cur])
            cur++;
        
        int bigger = (r - l + 1) - mex;
        expansion = mex - bigger;
        
    }
    cout << ans << endl;;
    
    
}

int32_t main() {
    int ct = 1;
    cin >> ct;
    while(ct--)
        solve();
    return 0;
}