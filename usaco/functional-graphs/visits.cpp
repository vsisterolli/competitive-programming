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
const ll mod = 1e9 + 7, MAXN = 1e5 + 5;
typedef vector<int> vi;
typedef pair<int, pair<int, int>> piii;

bool used[MAXN];
vector<pii> cycles;
vi v(MAXN), p(MAXN);

void th(int u) {
    used[u] = 1;

    int tt = v[u];
    int hr = v[v[u]];

    while(tt != hr && !used[tt]) {
        used[tt] = 1;
        tt = v[tt];
        hr = v[v[hr]];
    }

    if(tt != hr)
        return;

    tt = v[tt];
    while(1) {
        used[tt] = 1;
        if(v[tt] == hr) {
            cycles.pb({hr, tt});
            break;
        }
        tt = v[tt];
    }

    return;
}

int findSmall(int s, int t) {
    int small = p[s];
    while(s != t) {
        s = v[s];
        small = min(small, p[s]);
    }
    return small;
}

void solve() {
    int n;
    cin >> n;

    int ans = 0;
    for(int i = 0; i < n; i++) {
        cin >> v[i] >> p[i];
        v[i]--;
        ans += p[i];
    }

    for(int i = 0; i < n; i++) 
        if(!used[i])
            th(i);

    map<int, int> ap;
    for(pii &i : cycles) {
        if(ap[i.f] || ap[i.s])
            continue;
        ans -= findSmall(i.f, i.s);
        ap[i.f]++, ap[i.s]++;
    }
    cout << ans << endl;
}

int32_t main() {
    int ct = 1;
    // cin >> ct;
    while(ct--)
        solve();
    return 0;
}