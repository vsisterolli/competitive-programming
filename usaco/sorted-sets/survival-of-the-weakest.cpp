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

ll modExpo(ll a, ll b) {
    if(b == 0)
        return 1;
    if(b == 1)
        return a;
    
    ll prod = modExpo(a, b >> 1);

    prod = (prod * prod) % mod;

    if(b & 1)
        prod = (prod * a) % mod;

    return prod; 
}

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];
    
    sort(all(v));

    
    ll toSum = 0;
    sort(all(v));

    while(n) {

        
        int x = v[0];
        for(int i = 0; i < n; i++)
            v[i] -= x;
        
        toSum = (toSum + (x * modExpo(2, n - 1)) % mod)%mod;

        priority_queue<piii, vector<piii>, greater<piii>> fila;

        for(int i = 0; i + 1 < n; i++) 
            fila.push({v[i] + v[i + 1], {i, i + 1}});
    
        vector<int> v2;

        for(int i = 0; i + 1 < n; i++) {
            piii cur = fila.top();
            fila.pop();
            
            v2.pb(cur.f);
            cur.s.s++;

            if(cur.s.s < n)
                fila.push({v[cur.s.f] + v[cur.s.s], {cur.s.f, cur.s.s}});

        }

        v = v2;

        if(n == 1) {
            cout << (v[0] + toSum) % mod << endl;
            return;
        }
        n--;
    }
    
}

int32_t main() {
    FAST;
    int ct = 1;
    // cin >> ct;
    while(ct--)
        solve();
    return 0;
}