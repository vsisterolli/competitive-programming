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

int n, k;
int v[MAXN];


void solve() {
    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> v[i];
    sort(v, v + n);
    
    int l = 0, r = n - 1;
   
    while(k && l < r) {
        while(l + 1 < r && v[l] == v[l + 1])
            l++;
        while(r - 1 >= l && v[r] == v[r - 1])
            r--;

        if(l == r)
            break;
        
        int toRight = (n - 1) - r + 1;
        if(l + 1 <= toRight) {
            
            if( (l + 1) * (v[l + 1] - v[l]) <= k) {
                k -= (l + 1) * (v[l + 1] - v[l]);
                l++;
            }

            else {
                v[l] += k/(l + 1);
                k = 0;
            }
        
        }

        else {
            if(toRight * (v[r] - v[r - 1]) <= k) {
                k -= toRight * (v[r] - v[r - 1]);
                r--;
            }

            else {
                v[r] -= k/toRight;
                k = 0;
            }
        }
    }
    
    cout << v[r] - v[l] << endl;
}

int32_t main() {
    int ct = 1;
    // cin >> ct;
    while(ct--)
        solve();
    return 0;
}