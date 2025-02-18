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

    vector<int> b(n), g(m);

    int ans = 0;
    for(int &i : b) {
        cin >> i;
        ans += i * m;
    }
    
    for(int &i : g)
        cin >> i;

    sort(all(b));
    sort(all(g));

    if(g[0] < b.back() || (b.size() == 1 && g[0] > b[0])) {
        cout << -1 << endl;
        return;
    }

    for(int i = 1; i < m; i++) {

        auto aux = lb(all(b), g[i]);
        int bans = LINF;

        if(aux != b.end())
            bans = (*aux - g[i]);

        if(aux != b.begin()) {
            aux--;
            bans = min(bans, (g[i] - *aux));
        }

        ans += bans;
    }

    if(b.back() != g[0])
        b.pop_back();
    auto aux = lb(all(b), g[0]);
    int bans = LINF;

    if(aux != b.end())
        bans = (*aux - g[0]);

    if(aux != b.begin()) {
        aux--;
        bans = min(bans, (g[0] - *aux));
    }
    ans += bans;

    cout << ans << endl;

}

int32_t main() {
    int ct = 1;
    // cin >> ct;
    while(ct--)
        solve();
    return 0;
}