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

void dfs(vector<vector<int>> &g, vector<int> &used, int u) {
    used[u] = 1;
    for(int &i : g[u])
        if(!used[i])
            dfs(g, used, i);
}

int32_t main() {
    setIO("moocast");
    int n;
    cin >> n;

    vector<pii> v(n);
    for(pii &i : v)
        cin >> i.f >> i.s;
    
    ll ini = 1, mid, end = 1e12, ans = 1e12;
    while(ini <= end) {
        mid = (ini + end)/2;

        vector<vector<int>> g(n);
        vector<int> used(n);

        for(int i = 0; i < n; i++)
            for(int j = i + 1; j < n; j++) {
                int x = (v[i].f - v[j].f) * (v[i].f - v[j].f);
                int y = (v[i].s - v[j].s) * (v[i].s - v[j].s);
                if(x + y <= mid) {
                    g[i].pb(j); 
                    g[j].pb(i);
                }
            }
        
        dfs(g, used, 0);
        bool deu = true;
        for(int &i : used)
            deu &= i;
        
        if(deu) {
            end = mid - 1;
            ans = min(ans, mid);
        }
        else ini = mid + 1;
    }

    cout << ans << endl;
}