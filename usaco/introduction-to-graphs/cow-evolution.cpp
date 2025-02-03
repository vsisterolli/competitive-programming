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
const ll mod = 1e9 + 7, MAXN = 2e5 + 5;
typedef vector<int> vi;
typedef pair<int, pair<int, int>> piii;
// END HEADER


int32_t main() {

    setIO("evolution");
    int n;
    cin >> n;

    map<string, vector<int>> mapa;
    map<int, string> sbt;

    for(int i = 0; i < n; i++) {
        int q;
        cin >> q;
        while(q--) {
            string s;
            cin >> s;
            mapa[s].pb(i);
        }
    }

    vector<pair<int, string>> szs;
    for(auto i : mapa)
        szs.pb({i.s.size(), i.f});
    
    sort(szs.begin(), szs.end(), greater<pair<int, string>>());
    
    for(auto i : szs) {
        
        string cur = i.s;
        
        string sbtc = sbt[mapa[cur][0]];
        bool flag = true;
        for(auto j : mapa[cur]) {
            if(sbtc != sbt[j])
                flag = false;
            sbt[j] = cur;
        }

        if(!flag) {
            cout << "no" << endl;
            return 0;
        }


    }

    cout << "yes" << endl;
}

