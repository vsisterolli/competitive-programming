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
    setIO("tttt");
    mat m(3, vector<char>(3));
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            cin >> m[i][j];

    set<int> ind;
    set<pii> doub;
    for(int i = 0; i < 3; i++) {
        set<int> s1, s2;
        for(int j = 0; j < 3; j++) {
            s1.insert(m[i][j]);
            s2.insert(m[j][i]);
        }

        if(s1.size() == 1)
            ind.insert(*s1.begin());
        if(s2.size() == 1)
            ind.insert(*s2.begin());

        if(s1.size() == 2)
            doub.insert({*s1.begin(), *(++s1.begin())});
        if(s2.size() == 2)
            doub.insert({*s2.begin(), *(++s2.begin())});
    }

    

    set<int> s1, s2;
    for(int i = 0; i < 3; i++) {
        s1.insert(m[i][i]);
        s2.insert(m[0][2 - i]);
    }

    if(s1.size() == 1)
        ind.insert(*s1.begin());
    if(s2.size() == 1)
        ind.insert(*s2.begin());

    if(s1.size() == 2)
        doub.insert({*s1.begin(), *(++s1.begin())});
    if(s2.size() == 2)
        doub.insert({*s2.begin(), *(++s2.begin())});

    cout << ind.size() << endl << doub.size() << endl;
}

