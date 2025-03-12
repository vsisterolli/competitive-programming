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

map<int, int> exists;

void solve() {
    int n, q;
    cin >> n >> q;

    vector<int> v(n + 1), sum(n + 1), xr(n + 1), nz;
    for(int i = 1; i <= n; i++) {
        cin >> v[i];
        if(v[i])
            nz.pb(i);
        xr[i] = v[i] ^ xr[i - 1];
        sum[i] = v[i] + sum[i - 1];
    }
    
    while(q--) {
        int l, r;
        cin >> l >> r;
        int bestAns = (sum[r] - sum[l - 1]) - (xr[r] ^ xr[l - 1]);

        int bestSz = r - l + 1, bestl = l, bestr = r;
        for(int x = 0; x <= 31; x++) {
            int ansl = l;

            int ini = ansl, mid, end = r, ansr = r + 1;
            while(ini <= end) {
                mid = (ini + end)/2;
                if(bestAns == ((sum[mid] - sum[ansl - 1]) - (xr[mid] ^ xr[ansl - 1])) ) {
                    ansr = min(ansr, mid);
                    end = mid - 1;
                }
                else ini = mid + 1;
            }

            if(ansr <= r && ansr - ansl + 1 < bestSz)  {
                bestSz = ansr - ansl + 1;
                bestl = ansl;
                bestr = ansr;
            }

            auto it = upper_bound(all(nz), l);
            if(it == nz.end() || *it > r)
                break;
            
            l = *it;
        }
        cout << bestl << " " << bestr << endl;

    }
}

int32_t main() {
    int ct = 1;
    cin >> ct;
    while(ct--)
        solve();
    return 0;
}