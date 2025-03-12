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

int bmask = 0, bi = 1, bj = 2;

void divide(int bit, vector<pii> &g, int mask) {
    if(mask > bmask) {
        bmask = mask;
        bi = g[0].s + 1;
        bj = g[1].s + 1;
    }

    if(bit == -1)
        return;
    
    vector<pii> g1, g2;
    for(pii &i : g) {
        if((1<<bit) & i.f)
            g1.push_back(i);
        else
            g2.push_back(i);
    }
    // debug2(g1.size(), g2.size());
    if(g1.size() >= 2)
        divide(bit - 1, g1, (mask | (1<<bit)));
    if(g2.size() >= 2)
        divide(bit - 1, g2, (mask | (1<<bit)));
    
    if(g1.size() < 2 && g2.size() < 2)
        divide(bit - 1, g, mask);
            
    return;
}

void solve() {
    bmask = 0, bi = 1, bj = 2;
    int n, k;
    cin >> n >> k;

    vector<pii> v(n);
    for(int i = 0; i < n; v[i].s = i, i++)
        cin >> v[i].f;
    
    divide(k - 1, v, 0);
    int a1 = v[bi - 1].f;
    int a2 = v[bj - 1].f;
    cout << bi << " "  << bj << " " << (((1<<k) - 1) ^ (a1 & a2)) << endl;

}

int32_t main() {
    int ct = 1;
    cin >> ct;
    while(ct--)
        solve();
    return 0;
}