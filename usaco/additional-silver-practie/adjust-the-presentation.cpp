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

set<int> ap[MAXN];

int n, m, q;
bool incorrect(int x) {
    if(x > n || x == 1)
        return false;
    if(!ap[x].size())
        return false;
    if(!ap[x - 1].size())
        return true;
    if(*ap[x].begin() < *ap[x - 1].begin())
        return true;
    return false;
}

void solve() {
    cin >> n >> m >> q;
    for(int i = 1; i <= n; i++) 
        ap[i].clear();

    vi translate(n + 1);

    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        translate[x] = i;
    }

    vi b(m);
    for(int i = 0; i < m; i++) {
        int x;
        cin >> x;
        b[i] = translate[x];
        ap[b[i]].insert(i);
    }

    set<int> s;
    for(int i = 2; i <= n; i++) 
        if(incorrect(i))
            s.insert(i);
    
    cout << (!s.size() ? "YA" : "TIDAK") << endl;

    while(q--) {
        int x, y;
        cin >> x >> y;
        
        x--;
        y = translate[y];

        ap[b[x]].erase(x);
        ap[y].insert(x);

        s.erase(b[x]);
        s.erase(b[x] + 1);
        s.erase(y);
        s.erase(y + 1);
        
        // debug4(incorrect(b[x] + 1), incorrect(y + 1), incorrect(b[x]), incorrect(y));

        if(incorrect(b[x]))
            s.insert(b[x]);

        if(incorrect(b[x] + 1))
            s.insert(b[x] + 1);

        if(incorrect(y))
            s.insert(y);

        if(incorrect(y + 1))
            s.insert(y + 1);

        b[x] = y;
        // debug(s.size());
        cout << (!s.size() ? "YA" : "TIDAK") << endl;
    }
}

int32_t main() {
    int ct = 1;
    cin >> ct;
    while(ct--)
        solve();
    return 0;
}