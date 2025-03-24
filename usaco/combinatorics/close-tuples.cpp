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
const ll mod = 1e18, MAXN = 2e5 + 5;
typedef vector<int> vi;
typedef pair<int, pair<int, int>> piii;

int fat[MAXN], inv[MAXN];

void solve() {
    int n, m = 3, k = 2;
    cin >> n;
    
    
    map<int, int> ap;
    set<int> s;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        ap[x]++;
        s.insert(x);
    }
    vector<int> v;
    for(int i : s)
        v.push_back(i);
    
    int l = 0, tot = 0, ans = 0;
    for(int r = 0; r < v.size(); r++) {
        
        tot += ap[v[r]];
        while(v[r] - v[l] > k) 
            tot -= ap[v[l++]];
        
        if(tot >= m) {
            int choose = (fat[tot] / inv[tot - m])%mod;
            choose = (choose * inv[m])%mod;
            
            if(tot - ap[v[r]] >= m) {
                int ch2 = (fat[tot - ap[v[r]]] / inv[tot - ap[v[r]] - m])%mod;
                ch2 = (ch2 / inv[m])%mod;
                
                choose = (choose - ch2 + mod)%mod;
            }   
            
            ans = (ans + choose)%mod;
        }
    }
    cout << ans << endl;
    
    
}

int32_t main() {
    int ct = 1;
    cin >> ct;
    while(ct--)
    solve();
    return 0;
}