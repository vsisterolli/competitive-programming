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
const ll mod = 998244353, MAXN = 2e5 + 5;
typedef vector<int> vi;
typedef pair<int, pair<int, int>> piii;
// END HEADER

int32_t main() {
    FAST;
    int n, x;
    cin >> n >> x;

    vector<pii> v(n);
    map<int, int> ind;
    map<int, vector<pii>> db;

    int aux = 1;
    for(pii &i : v) {
        cin >> i.f;
        i.s = aux++;
        ind[i.f]++;
    }
    sort(v.begin(), v.end());

    for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++)
            db[v[i].f + v[j].f].pb({i, j});
    
    for(int i = 0; i < n; i++) 
        for(int j = i+1; j < n; j++) {

            int aux = x - (v[i].f + v[j].f);
            if(aux <= 0)
                break;

            vector<pii> *v2 = &db[aux];    
            int kek = (*v2).size();
            if(kek == 0)
                continue;

            int aux2 = aux - v[i].f, aux3 = aux - v[j].f;
            

            if(kek - (ind[aux2] - (aux2 == v[i].f)) - (ind[aux3] - (aux3 == v[j].f) - (aux3 == v[i].f)) > 0) {
                
                for(pii k : *v2) 
                    if(k.f != i && k.f != j && k.s != i && k.s != j && k.f != k.s) {
                        cout << v[i].s << " " << v[j].s << " " << v[k.f].s << " " << v[k.s].s << endl;
                        return 0;
                    }
            }
        }
    cout << "IMPOSSIBLE" << endl;
        
}
