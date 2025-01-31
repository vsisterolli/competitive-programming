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
const ll mod = 998244353, MAXN = 4e5 + 5;
typedef vector<int> vi;
typedef pair<pair<int, int>, int> piii;
// END HEADER

int32_t main() {
    FAST;   
    int n;
    cin >> n;

    vector<piii> v(n);
    int aux = 0;
    for(piii &i : v) {
        cin >> i.f.f >> i.f.s;
        i.s = aux++;
    }
    sort(v.begin(), v.end());

    multiset<int> rooms;
    vector<int> ans(n);
    map<int, set<int>> mapa;

    for(piii &i : v) {
        auto lbs = rooms.lb(i.f.f);
        if(lbs == rooms.begin()) {
            rooms.insert(i.f.s);
            ans[i.s] = rooms.size();
            if(!mapa[i.f.s].size())
                mapa[i.f.s] = {};
            mapa[i.f.s].insert(rooms.size());
            continue;
        }
        lbs--;
        ans[i.s] = *mapa[*lbs].begin();
        mapa[*lbs].erase(mapa[*lbs].begin());
        rooms.erase(lbs);

        mapa[i.f.s].insert(ans[i.s]);
        rooms.insert(i.f.s);
    }

    cout << rooms.size() << endl;
    for(int &i : ans)
        cout << i << " ";
}
