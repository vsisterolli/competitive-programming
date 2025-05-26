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
typedef pair<double, double> pii;
typedef vector<vector<char>> mat;
typedef pair<int, string> pis;
const ll mod = 1e9 + 7, MAXN = 2e5 + 5;
typedef vector<int> vi;
typedef pair<int, pair<int, int>> piii;

void solve() {
    int r, n, a, m, s;
    cin >> r >> n >> a >> m >> s;
    a *= 3600;
    m *= 60;
    m += s;
    a += m;

    const int tot = 1296000;
    int aux = 0;

    vector<bool> ap(tot + 5);
    ap[0] = 1;
    int last = 0;
    for(int i = 0; i < n - 1; i++) {
        aux += a;
        if(aux >= tot)
            aux -= tot;
        if(ap[aux])
            break;
        ap[aux] = 1;
    }


    double ans = 0;
    for(int i = 0; i < tot; i++) {
        if(!ap[i])
            continue;
        
        int dist = abs(i - last);
        last = i;
        ans = max(ans, r * r * M_PI * (double)dist/double(tot));
    }
    int dist = tot - last;
    ans = max(ans, r * r * M_PI * (double)dist/double(tot));
    
    cout << fixed << setprecision(6) << ans << endl;
}

int32_t main() {
    FAST;
    int ct = 1;
    cin >> ct;
    while(ct--)
        solve();
    return 0;
}