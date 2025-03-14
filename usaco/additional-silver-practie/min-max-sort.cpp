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
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];
    
    bool ordered = 1;
    for(int i = 0; i < n; i++) 
        if(v[i] != i + 1)
            ordered = false;
    if(ordered) {
        cout << 0 << endl;
        return;
    }

    int ini = 1, mid, end = n/2, ans = n/2;
    while(ini <= end) {
        mid = (ini + end)/2;
        
        int l = 1, r = n;
        l += mid - 1;
        r -= mid - 1;

        vector<int> newV;
        for(int &i : v)
            if(i > l && i < r)
                newV.pb(i);

        ordered = 1;
        for(int i = 0; i + 1 < newV.size(); i++) 
            if(newV[i] > newV[i + 1])
                ordered = false;
        
        if(ordered) {
            ans = min(ans, mid);
            end = mid - 1;
        }
        else ini = mid + 1;

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