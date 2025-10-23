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

int32_t main() {
    int n, x;
    cin >> n >> x;
    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];


    int mx = (1<<n);

    pii dp[mx];

    dp[0] = {0, 0};
    for(int i = 1; i < mx; i++) {
        int aux = i;
        dp[i] = {1e9, 1e9};
        while(aux) {
            
            int bit = (aux & (-aux));
            aux ^= bit;

            pii cur = dp[i ^ bit];
            cur.s += v[63 - __builtin_clzll(bit)];
            if(!cur.f)
                cur.f++;

            if(cur.s > x) {
                cur.s = v[63 - __builtin_clzll(bit)];
                cur.f++;
            }
            dp[i] = min(dp[i], cur);
        }
    }
    cout << dp[mx - 1].f << endl;
}