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
#define all(x) (x).begin(), (x).end()
#define left esquerda
#define lb lower_bound
#define int long long
#define right direita
using namespace std;
void setIO(string s) {
ios_base::sync_with_stdio(0); cin.tie(0);
freopen((s+".in").c_str(),"r",stdin);
freopen((s+".out").c_str( ),"w",stdout);
}
typedef pair<int, int> pii;
typedef vector<vector<char>> mat;
typedef pair<int, string> pis;
const ll mod = 1e9 + 7, MAXN = 2e5 + 5;
typedef vector<int> vi;
typedef pair<int, pair<int, int>> piii;

void solve() {
    int n;
    cin >> n;


    map<int, vector<int>> horz, vert, sumhorz, sumvert;

    vector<pii> v(n);
    for(pii &i : v) {
        cin >> i.f >> i.s;
        vert[i.f].pb(i.s);
        horz[i.s].pb(i.f);
   }

    sort(all(v));
    for(auto i : vert) {
        sort(all(i.s));
        for(int j = 0; j < i.s.size(); j++) {
            int aux = (!j ? 0 : sumvert[i.f][j - 1]);
            sumvert[i.f].pb(aux + i.s[j]);
        }
    }
    
    for(auto i : horz) {
        sort(all(i.s));
        for(int j = 0; j < i.s.size(); j++) {
            int aux = (!j ? 0 : sumhorz[i.f][j - 1]);
            sumhorz[i.f].pb(aux + i.s[j]);
        }
    }

    int ans = 0;

    for(pii &cur : v) {
        int ini = 0, mid, end = horz[cur.s].size() - 1, best = -1;
        while(ini <= end) {
            mid = (ini + end)/2;

            if(horz[cur.s][mid] > cur.f)
                end = mid -  1;
            else {
                best = max(best, mid);
                ini = mid + 1;
            }

        }  

        int horir = 0;
        horir += (best + 1) * cur.f - sumhorz[cur.s][best];
        horir += (sumhorz[cur.s].back() - sumhorz[cur.s][best]) - cur.f * (horz[cur.s].size() - 1 - best);
    
    
        int verr = 0;

        ini = 0, mid, end = vert[cur.f].size() - 1, best = -1;
        while(ini <= end) {
            mid = (ini + end)/2;

            if(vert[cur.f][mid] > cur.s)
                end = mid -  1;
            else {
                best = max(best, mid);
                ini = mid + 1;
            }

        }


        verr += (best + 1) * cur.s - sumvert[cur.f][best];
        
        verr += (sumvert[cur.f].back() - sumvert[cur.f][best]) - cur.s * (sumvert[cur.f].size() - 1 - best);
    
        
        ans = (ans + (verr * horir)%mod)%mod;
    }

    cout << ans << endl;
}

int32_t main() {
    setIO("triangles");  
    int ct = 1;
    // cin >> ct;
    while(ct--)
        solve();
}