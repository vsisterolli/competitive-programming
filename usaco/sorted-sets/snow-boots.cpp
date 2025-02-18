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
    int n, b;
    cin >> n >> b;

    vector<int> f(n);

    set<int> un;
    for(int &i : f) {
        cin >> i;
        un.insert(i);
    }

    vector<pii> bts(b);
    for(pii &i : bts) {
        cin >> i.f >> i.s;
        un.insert(i.f);
    }
    vector<int> compress;
    for(auto i : un)
        compress.pb(i);


    map<int, int> cmp;
    for(int i = 0; i < compress.size(); i++) 
        cmp[compress[i]] = i;
    
    
    vector<int> pos[compress.size()], ans(compress.size());
    
    for(int i = 0; i < n; i++) {
        f[i] = cmp[f[i]];
        pos[f[i]].pb(i);
    }
    
    for(int i = 0; i < b; i++)
        bts[i].f = cmp[bts[i].f];
    
    set<int> curpos;
    multiset<int> dists;

    curpos.insert(0);
    curpos.insert(n - 1);

    dists.insert(n - 1);
    for(int i = 0; i < compress.size(); i++) {
        for(int &j : pos[i]) {
            if(j == 0 || j == n - 1)
                continue;

            curpos.insert(j);
            auto aux = curpos.upper_bound(j);
            dists.insert(*aux - j);

            auto aux2 = curpos.lower_bound(j);
            aux2--;

            dists.insert(j - *aux2);
            dists.erase(dists.find(*aux - *aux2));
        }
        
        auto curans = dists.end();
        curans--;
        ans[i] = *curans;

    }

    for(int i = 0; i < b; i++)
        cout << (bts[i].s >= ans[bts[i].f]) << endl;

}

int32_t main() {
    setIO("snowboots");
    int ct = 1;
    // cin >> ct;
    while(ct--)
        solve();
    return 0;
}