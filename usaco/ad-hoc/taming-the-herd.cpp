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
using namespace std;
void setIO(string s) {
ios_base::sync_with_stdio(0); cin.tie(0);
freopen((s+".in").c_str(),"r",stdin);
freopen((s+".out").c_str( ),"w",stdout);
}
typedef pair<ll, ll> pii;
typedef vector<vector<char>> mat;
typedef pair<int, string> pis;
const ll mod = 1e9 + 7, MAXN = 2e5 + 5;
typedef vector<int> vi;
typedef pair<int, pair<int, int>> piii;
// END HEADER


int32_t main() {
    setIO("taming");
    int n;
    cin >> n;
    vector<int> v(n), aux(n + 1);

    int ans = 0;
    for(int i = 0; i < n; i++) 
        cin >> v[i];
    if(v[0] > 0) {
        cout << -1 << endl;
        return 0;
    }
    
    for(int i = 0; i < n; i++) 
        if(v[i] > 0)
            for(int j = i-1; j >= 0; j--) {
                if(v[j] != -1)
                    break;
                v[j] = v[j + 1] - 1;
                if(!v[j]) break;
            }
    if(v[0] > 0) {
        cout << -1 << endl;
        return 0;
    }
    v[0] = 0;


    for(int i = 0; i < n; i++) {
        if( (v[i] > i) || ( ((i + 1 < n) && (v[i + 1] > 0) && (v[i + 1] - v[i] != 1)) ) ) {
            cout << -1 << endl;
            return 0;
        }
    }
    int mx = 0, mn = 0;
    for(int i = 0; i < n; i++) {
        mx += (v[i] <= 0);
        mn += (v[i] == 0);
    }
    
    cout << mn << " " << mx << endl;
    
}

