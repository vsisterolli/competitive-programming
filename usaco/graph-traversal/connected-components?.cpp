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

void solve() {
    int n, m;
    cin >> n >> m;

    map<pii, bool> del;
    vector<int> g(n);
    set<int> no_comp;

    for(int i = 0; i < n; i++)
        no_comp.insert(i);

    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;

        del[{a, b}] = del[{b, a}] = 1;
        
        g[a]++;
        g[b]++;
    }
    
    queue<int> q;
    vi ans;

    for(int i = 0; i < n; i++) {
        if(no_comp.find(i) == no_comp.end())
            continue;
        
        q.push(i);
        int anssz = 0;
        while(!q.empty()) {
            int cur = q.front();
            q.pop();
            anssz++;

            no_comp.erase(cur);

            vector<int> trmv;
            for(int i : no_comp) 
                if(!del[{i, cur}] && !del[{cur, i}]) {
                    trmv.push_back(i);
                    q.push(i);
                }
                
            for(int &i : trmv) 
                no_comp.erase(i);
        
            
        }
        ans.push_back(anssz);
    }

        

    sort(all(ans));
    cout << ans.size() << endl;
    for(int &i : ans)
        cout << i << " ";
    cout << endl;
    
}

int32_t main() {
    int ct = 1;
    // cin >> ct;
    while(ct--) 
        solve();
    return 0;
}