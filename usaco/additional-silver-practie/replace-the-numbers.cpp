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
const ll mod = 1e9 + 7, MAXN = 5e5 + 5;
typedef vector<int> vi;
typedef pair<int, pair<int, int>> piii;


void solve() {
    int q;
    cin >> q;
   
    vector<array<int, 3>> v(q);
    for(int i = 0; i < q; i++) {
        cin >> v[i][0] >> v[i][1];
        if(v[i][0] == 2)
            cin >> v[i][2];
    }

    map<int, int> mapa;
    vector<int> ans;

    for(int i = q - 1; i >= 0; i--) {
        if(v[i][0] == 1) {
            if(mapa[v[i][1]])
                ans.push_back(mapa[v[i][1]]);
            else ans.push_back(v[i][1]);
        }   
        else {
            mapa[v[i][1]] = (mapa[v[i][2]] ? mapa[v[i][2]] : v[i][2]);
        }
    }
    reverse(all(ans));
    for(int &i : ans)
        cout << i << " ";
    cout << endl;

   
}

int32_t main() {
    FAST;
    int ct = 1;
    // cin >> ct;
    while(ct--)
        solve();
    return 0;
}