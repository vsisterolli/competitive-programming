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
typedef pair<ll, ll> pii;
typedef vector<vector<char>> mat;
typedef pair<int, string> pis;
const ll mod = 1e9 + 7, MAXN = 2e5 + 5;
typedef vector<int> vi;
typedef pair<int, pair<int, int>> piii;

void solve() {
    int n;
    cin >> n;
    
    vi v(n), ans(n + 1);
    for(int &i : v)
        cin >> i;
    
    vector<array<int, 3>> list;
    for(int i = 0; i < n; i++) {
        for(auto &j : list)
            j[2] = __gcd(j[2], v[i]);
        
        list.push_back({i, i, v[i]});
        
        int sz = 0;
        for(int j = 0; j < list.size(); j++) {
            if(sz && list[sz - 1][2] == list[j][2]) 
                list[sz - 1][1] = list[j][1];
            else
                list[sz++] = list[j];
        }
        list.resize(sz);
        
        for(auto &j : list) 
            if(ans[i - j[0] + 1] < j[2])            
                ans[i - j[0] + 1] = j[2];
        
    }

    for(int i = 1; i <= n; i++)
        cout << ans[i] << " ";
    cout << endl;
}

int32_t main() {
    FAST;
    int ct = 1;
    cin >> ct;
    while(ct--)
        solve();
    return 0;
}