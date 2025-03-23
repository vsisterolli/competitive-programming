#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <chrono>
#define pb push_back
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define endl '\n'
#define ll long long
#define int long long
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
typedef pair<ll, ll> pii;
typedef vector<vector<char>> mat;
typedef pair<int, string> pis;
const ll mod = 1e9 + 7, MAXN = 2e5 + 5;
typedef vector<int> vi;
typedef pair<int, pair<int, int>> piii;

long long f(int l, int p) {
    int w = l/p;
    int p2 = l % p;
    int p1 = p - p2;
    return p1 * w * w + p2 * (w + 1) * (w + 1);
}

void solve() {
    int n, k;
    cin >> n >> k;

    long long ans = 0;
    priority_queue<array<int, 3>> q;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        ans += 1ll * x * x;
        q.push({f(x, 1) - f(x, 2), x, 1});
    }    

    for(int i = 0; i < k - n; i++) {
        auto [val, l, p] = q.top();
        q.pop();

        p++;
        ans -= val;
        q.push({f(l, p) - f(l, p + 1), l, p});
    }
    cout << ans << endl;
}

int32_t main() {
    FAST;
    int ct = 1;
    // cin >> ct;
    while(ct--)
        solve();
    return 0;
}