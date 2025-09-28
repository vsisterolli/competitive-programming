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
 
map<int, int> ss, ff;
 
int n, k;
int query(char T, int v) {
    if(v > n && (T == 'F' || T == 'S'))
        return -1;
    if(v < 1)
        return 1e9 + 5;
    if(T == 'F' && ff[v])
        return ff[v];
    if(T == 'S' && ss[v])
        return ss[v];
    cout << T << " " << v << endl << flush;
    if(T == '!')
        return -1;  
 
    int x;
    cin >> x;
 
    if(T == 'F')
        ff[v] = x;
    else
        ss[v] = x;
    return x;
}
 
void solve() {
    cin >> n >> k;
    
    int ini = 1, mid, end = min(k,n), last = 0;  
    
    int l = 1, r = n;
 
    while(ini <= end) {
        mid = (ini + end) / 2;
        if(query('S', mid) < query('F', k - mid) && query('S', mid) > query('F', k - mid + 1)) {
            query('!', query('S', mid));
            return;
        }
        else if(query('S', mid) > query('F', k - mid)) 
            ini = mid + 1;
        else end = mid - 1;
    }
 
    ini = 1, mid, end = n;
 
    while(ini <= end) {
        mid = (ini + end) / 2;
        if(query('F', mid) < query('S', k - mid) && query('F', mid) > query('S', k - mid + 1)) {
            query('!', query('F', mid));
            return;
        }
        else if(query('F', mid) > query('S', k - mid)) 
            ini = mid + 1;
        else end = mid - 1;
    }
 
 
}
 
int32_t main() {
    int ct = 1;
    // cin >> ct;
    while(ct--)
        solve();
    return 0;
}