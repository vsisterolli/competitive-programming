// HELPFUL HEADER ONLY
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
#define debug(x) cout << "DEBUG " << x << endl
#define debug2(x, y) cout << "DEBUG " << x << " " << y << endl
#define debug3(x, y, z) cout << "DEBUG " << x << " " << y << " " << z<< endl
#define debug4(x, y, z, o) cout << "DEBUG " << x << " " << y << " " << z<< " " << o << endl
#define all(x) x.begin(), x.end()
#define left esquerda
#define lb lower_bound
#define right direita
#define int long long
using namespace std;
void setIO(string s) {
ios_base::sync_with_stdio(0); cin.tie(0);
freopen((s+".in").c_str(),"r",stdin);
freopen((s+".out").c_str( ),"w",stdout);
}
typedef pair<ll, ll> pii;
typedef vector<vector<char>> mat;
typedef pair<int, string> pis;
const ll mod = 998244353, MAXN = 2e5 + 5;
typedef vector<int> vi;
typedef pair<int, pair<int, int>> piii;
// END HEADER
 
int32_t main() {
    int n, a, b;
    cin >> n >> a >> b;
 
    vector<int> v(n);
    for(int &i : v)
        cin >> i;
 
    ll sum = 0, ans = -LINF;
    int l = 0, r = 0;
 
    while(r - l < a) 
        sum += v[r++];
    
    multiset<int> ps;
    vector<int> pastsums;
    while(r - l < b) {
        pastsums.pb(sum);
        ps.insert(sum);
        sum += v[r++];
    }
    pastsums.pb(sum);
    ps.insert(sum);
 
    auto aux = ps.end();
    aux--;
    ans = *aux;
 
    int xd = 0, tadd = 0;
    while(r < n) {
        
        sum += v[r];
        sum -= v[l];
        ps.erase(ps.find(pastsums[xd++]));
        
        tadd += v[l];
        ps.insert(sum + tadd);
        pastsums.pb(sum + tadd);
 
        aux = ps.end();
        aux--;
        ans = max(ans, *aux - tadd);
        
        l++;
        r++;
    }
 
    while(r - l > a) {
        sum -= v[l];
        ps.erase(ps.find(pastsums[xd++]));

        tadd += v[l];
        ps.insert(sum + tadd);
        pastsums.pb(sum + tadd);

        l++;

        aux = ps.end();
        aux--;
        ans = max(ans, *aux - tadd);

    }


    cout << ans << endl;
}