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
    int n,q ;
    cin >> n >> q;

    vi v(n), xr(n);
    for(int &i : v)
        cin >> i;
    reverse(all(v));

    xr[0] = v[0];
    for(int i = 1; i < n; i++)
        xr[i] = v[i] ^ xr[i - 1];

    vector<int> ap[30];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < 30; j++)
            if( (1<<j) & v[i])
                ap[j].push_back(i);

    while(q--) {
        int x;
        cin >> x;
        int cur = -1, lim = n - 1;

        for(int i = 29; i >= 0; i--) {
            auto it = upper_bound(all(ap[i]), cur);
            if(it == ap[i].end() || *it > lim)
                continue;
                
            int aux = x ^ (*it == 0 ? 0 : xr[*it - 1]);
            // debug4(i, *it, cur, lim);
            // debug(aux);
            if(aux >= v[*it]) {
                cur = *it;
                i++;
            }
            else lim = *it - 1;
        }

        cout << cur + 1 << " ";
    }
    cout << endl;
}

int32_t main() {
    int ct = 1;
    cin >> ct;
    while(ct--)
        solve();
    return 0;
}