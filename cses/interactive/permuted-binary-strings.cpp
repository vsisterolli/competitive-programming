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

void solve() {
    int n;
    cin >> n;

    if(n == 1) {
        cout << "! " << 1 << endl << flush;
        return;
    }

    vector<vector<int>> blocks, pps;
    
    vector<int> aux;
    for(int i = 1; i <= n; i++) 
        aux.push_back(i);
    blocks.push_back(aux);
    pps.push_back(aux);

    vector<int> res(n + 1);
    while(!blocks.empty()) {

        string ans(n, '0');
        for(int i = 0; i < blocks.size(); i++) {
            for(int j = 0; j < blocks[i].size() / 2; j++)
                ans[blocks[i][j] - 1] = '1';
        
            // for(int &j : blocks[i])
            //     cout << j << " ";
            // cout << endl;
            // for(int &j : pps[i])
            //     cout << j << " ";
            // cout << endl << endl;
        }

        cout << "? " << ans << endl << flush;

        string q;
        cin >> q;
    
        vector<vector<int>> nblocks, npps;
        for(int i = 0; i < blocks.size(); i++) {
            vector<int> l, r, lpp, rpp;
            for(int j = 0; j < blocks[i].size() / 2; j++) 
                l.push_back(blocks[i][j]);
            for(int j = blocks[i].size() / 2; j < blocks[i].size(); j++)
                r.push_back(blocks[i][j]);
            
            for(int j = 0; j < pps[i].size(); j++) {
                if(q[pps[i][j] - 1] == '0')
                    rpp.push_back(pps[i][j]);
                else lpp.push_back(pps[i][j]);
            }

            if(l.size() == 1) {
                res[lpp[0]] = l[0];
            }
            else if(l.size()) {
                nblocks.push_back(l);
                npps.push_back(lpp);
            }

            if(r.size() == 1)  {
                res[rpp[0]] = r[0];
            }
            else if(r.size()) {
                nblocks.push_back(r);
                npps.push_back(rpp);
            }
        }

        blocks = nblocks;
        pps = npps;
    }

    cout << "! ";
    for(int i = 1; i <= n; i++)
        cout << res[i] << " ";
    cout << endl;
}

int32_t main() {
    int ct = 1;
    // cin >> ct;
    while(ct--)
        solve();
    return 0;
}