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

void solve() {
    int n;
    cin >> n;

    vector<pii> v(n);

    vector<int> aux;
    for(pii &i : v) {
        cin >> i.f >> i.s;
        aux.pb(i.f);
    }
    sort(aux.begin(), aux.end());

    map<int, int> cmp, rcmp;
    for(int i = 0; i < aux.size(); i++) {
        cmp[aux[i]] = i + 1;
        rcmp[i + 1] = aux[i];
    }

    priority_queue<pii> fila;
    vector<int> ans(aux.size() + 5);
    vector<bool> considered(aux.size() + 5, 1);
    for(pii &i : v) {
        i.f = cmp[i.f];

        ans[i.f] = max(ans[i.f], i.s);
        fila.push({ans[i.f], i.f});
    }
    
    while(!fila.empty()) {

        auto [curans, cur] = fila.top();
        fila.pop();

        if(curans != ans[cur])
            continue;
        

        if(cur > 1 && considered[cur - 1] && ans[cur - 1] <= ans[cur] - (rcmp[cur] - rcmp[cur - 1])) {
            considered[cur - 1] = 0;
            ans[cur - 1] = ans[cur] - (rcmp[cur] - rcmp[cur - 1]);
            fila.push({ans[cur - 1], cur - 1});
        }

        if(cur < n && considered[cur + 1] && ans[cur + 1] <= ans[cur] - (rcmp[cur + 1] - rcmp[cur])) {
            considered[cur + 1] = 0;
            ans[cur + 1] = ans[cur] - (rcmp[cur + 1] - rcmp[cur]);
            fila.push({ans[cur + 1], cur + 1});
        }
    }

    int res = n;
    for(pii &i : v) 
        res -= !(considered[i.f]);
    

    cout << res << endl;
}

int32_t main() {
    setIO("mountains");
    int ct = 1;
    while(ct--)
        solve();
}