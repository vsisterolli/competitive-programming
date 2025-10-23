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
    vector<int> v(n);
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        v[a] |= (1LL<<b);
        v[b] |= (1LL<<a);
    }

    int mx = 1<<min(n, 20LL);
    
    vector<bool> dp(mx), dp2(mx);
    dp[0] = 1;
    for(int i = 1; i < mx; i++) 
        for(int j = 0; j < min(n, 20LL); j++) 
            if( ((1<<j) & i) && !(v[j] & i) )
                dp[i] = (dp[i] | dp[i ^ (1<<j)]);
    
    
    dp2[0] = 1;
    for(int i = 1; i < mx; i++) 
        for(int j = 20; j < n; j++) {
            int x = (j - 20);
            if( ((1<<x) & i) && !( (v[j]>>20LL) & i) )
                dp2[i] = (dp2[i] | dp2[i ^ (1<<x)]);
        }

    vector<int> dp3(mx);
    for(int i = 1; i < mx; i++) {
        if(dp2[i]) { dp3[i] = i; continue; }
        for(int j = 20; j < n; j++) {
            int x = j - 20;
            if(!(i & (1<<x)))
                continue;

            if(__builtin_popcountll(dp3[i ^ (1<<x)]) > __builtin_popcountll(dp3[i]))
                dp3[i] = dp3[i ^ (1<<x)];
        }
    }

    int ans = 0;
    for(int i = 0; i < mx; i++) {
        if(!dp[i])
            continue;

        int can = mx - 1;
        for(int j = 0; j < min(n, 20ll); j++) 
            if((1<<j) & i)
                can &= ( (mx - 1) ^ (v[j] >> 20));
        
        if(__builtin_popcountll(ans) < __builtin_popcountll(i | (dp3[can]<<20LL) ))
            ans = i | (dp3[can]<<20LL);
    }

    cout << __builtin_popcountll(ans) << endl;
    for(int i = 0; i < n; i++)
        if((1LL<<i) & ans)
            cout << i << " ";
    if(__builtin_popcountll(ans))
        cout << endl;
}

int32_t main() {
    int ct = 1;
    // cin >> ct;
    while(ct--)
        solve();
    return 0;
}