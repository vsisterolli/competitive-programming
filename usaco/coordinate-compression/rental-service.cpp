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
#define FAST cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
#define debug(x) cout << "DEBUG " << x << endl
#define debug2(x, y) cout << "DEBUG " << x << " " << y << endl
#define debug3(x, y, z) cout << "DEBUG " << x << " " << y << " " << z<< endl
#define debug4(x, y, z, o) cout << "DEBUG " << x << " " << y << " " << z<< " " << o << endl
#define all(x) x.begin(), x.end()
#define left esquerda
#define lb lower_bound
#define right direita
#define int long long
using namespace std;
void setIO(string s) {
ios_base::sync_with_stdio(0); cin.tie(0);
freopen((s+".in").c_str(),"r",stdin);
freopen((s+".out").c_str( ),"w",stdout);
}
typedef pair<ll, ll> pii;
typedef vector<vector<char>> mat;
typedef pair<int, string> pis;
const ll mod = 1e9 + 7, MAXN = 2e5 + 5;
typedef vector<int> vi;
typedef pair<int, pair<int, int>> piii;

bool cmp(pii a, pii b){
    return a.s > b.s;
}

void solve() {
    int n, m, r;
    cin >> n >> m >> r;

    vector<int> cows(n);
    for(int &i : cows)
        cin >> i;

    vector<pii> stores(m);
    for(pii &i : stores)
        cin >> i.f >> i.s;
    
    vector<int> rents(r);
    for(int &i : rents)
        cin >> i;
    
    sort(all(rents), greater<int>());
    sort(all(cows), greater<int>());
    sort(all(stores), cmp);
    
    int sptr = 0, ans = 0;
    vector<int> ss;
    for(int &i : cows) {
        int aux = 0;
        while(sptr < m && i) {
            int rmv = min(stores[sptr].f, i);
            aux += rmv * stores[sptr].s;
            stores[sptr].f -= rmv;
            i -= rmv;

            if(!stores[sptr].f)
                sptr++;
        }
        ss.pb(aux);
        ans += aux;
    }

    sort(all(ss));

    int rptr = 0;
    for(int &i : ss) {
        if(rptr < r && rents[rptr] - i > 0)
            ans += rents[rptr++] - i;
    }

    cout << ans << endl;
}

int32_t main() {
    setIO("rental");
    int ct = 1;
    // cin >> ct;
    while(ct--)
        solve();
}