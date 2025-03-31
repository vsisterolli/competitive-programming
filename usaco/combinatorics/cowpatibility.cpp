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
const ll mod = 1e9 + 7, MAXN = 2e5 + 5;
typedef vector<int> vi;
typedef pair<int, pair<int, int>> piii;

map<vector<int>, int> ap;

int countValids(vi &v, int i, vi &cur) {
    if(i == 5) {
        sort(all(cur));
        return ((int)cur.size() & 1 ? ap[cur] : -ap[cur]);
    }
    vi ncur = cur;
    ncur.push_back(v[i]);

    return countValids(v, i + 1, cur) + countValids(v, i + 1, ncur);    
}

void genAp(vector<int> &v, int i, vi &cur) {
    if(i == 5) {
        sort(all(cur));
        if(cur.size())
            ap[cur]++;
        return;
    }

    vi ncur = cur;
    ncur.push_back(v[i]);

    genAp(v, i + 1, cur); genAp(v, i + 1, ncur);
    return;
}

void solve() {
    int n;
    cin >> n;

    vector<vector<int>> v(n, vector<int>(5));
    for(int i = 0; i < n; i++) 
        for(int j = 0; j < 5; j++) 
            cin >> v[i][j];
    
            vi aux;
    for(int i = 0; i < n; i++)
        genAp(v[i], 0, aux);


    int ans = 0;
    for(int i = 0; i < n; i++) 
        ans += n - countValids(v[i], 0, aux);
    
    cout << ans/2 << endl;
}

int32_t main() {
    setIO("cowpatibility");
    int ct = 1;
    while(ct--)
        solve();
    return 0;
}