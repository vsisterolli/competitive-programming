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
    int k, n, m;
    cin >> k >> m >> n;

    vector<pii> grass(k);
    for(pii &i : grass)
        cin >> i.f >> i.s;
    
    vector<int> cows(m);
    for(int &i : cows)
        cin >> i;

    sort(all(cows));

    int tastiness[m][2];
    memset(tastiness, 0, sizeof tastiness);

    vector<piii> trmv[m];

    for(pii &i : grass) {
        int ini = 0, mid, end = m - 1, l = -1;
        while(ini <= end) {
            mid = (ini + end)/2;
            if(cows[mid] <= i.f) {
                l = max(l, mid);
                ini = mid + 1;
            }
            else end = mid - 1;
        }
        if(l == -1) 
            tastiness[0][0] += i.s;
        else if(l == n - 1)
            tastiness[n - 1][1] += i.s;
        else {

            if( (i.f - cows[l]) < (cows[l + 1] - i.f))
                tastiness[l][1] += i.s;
            else if((i.f - cows[l]) > (cows[l + 1] - i.f))
                tastiness[l + 1][0] += i.s;
            else {
                tastiness[l][1] += i.s;
                tastiness[l + 1][0] += i.s;
                trmv[l].pb({l + 1, {i.s, 0}});
                trmv[l+1].pb({l, {i.s, 1}});
            }
        }
        
    }
    
    set<piii> s;
    for(int i = 0; i < m; i++) {
        s.insert({tastiness[i][0], {i, 0}});
        s.insert({tastiness[i][1], {i, 1}});
    }

    int ans = 0;
    while(n && !s.empty()) {
        auto aux = s.end();
        aux--;

        int toAdd = (*aux).f, cow = (*aux).s.f, type = (*aux).s.s;
    
        ans += toAdd;
        for(piii &i : trmv[cow]) {
            if(tastiness[i.f][i.s.s] == -1)
                continue;

            s.erase({tastiness[i.f][i.s.s], {i.f, i.s.s}});
            tastiness[i.f][i.s.s] -= i.s.f;
            s.insert({tastiness[i.f][i.s.s], {i.f, i.s.s}});
        }
        
        tastiness[cow][type] = -1;
        s.erase({toAdd, {cow, type}});
        n--;
        
    }
    cout << ans << endl;
}

int32_t main() {
    int ct = 1;
    // cin >> ct;
    while(ct--)
        solve();
    return 0;
}