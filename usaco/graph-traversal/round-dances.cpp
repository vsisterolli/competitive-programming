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

int pai[MAXN], sz[MAXN];

void startDsu(int n) {
    for(int i = 0; i <= n; i++) {
        pai[i] = i;
        sz[i] = 1;
    }
}

int find(int u) {
    if(pai[u] != u)
        return pai[u] = find(pai[u]);
    return u;
}

void join(int a, int b) {
    a = find(a), b = find(b);
    if(a == b) return;

    if(sz[a] > sz[b])
        swap(a, b);

    pai[a] = b;
    if(sz[a] == sz[b])
        sz[b]++;
}

void solve() {
    int n;
    cin >> n;

    startDsu(n);

    vector<int> v(n), dg(n);
    
    map<pii, bool> ap;
    for(int i = 0; i < n; i++) {
        cin >> v[i];
        v[i]--;

        join(v[i], i);
        if(!ap[{v[i], i}] && !ap[{i, v[i]}]) {
            dg[i]++;
            dg[v[i]]++;
        }
       
        ap[{v[i], i}] = ap[{i, v[i]}] = 1;
    }  

    int ansMx = 0;
    for(int i = 0; i < n; i++) 
        ansMx += (find(i) == i);
    
    int ansMn = ansMx;
    for(int i = 0; i < n; i++) {
        int found = n;
        if(dg[i] == 1) {
            for(int j = i + 1; j < n; j++)
                if(dg[j] == 1 && find(i) != find(j)) {
                    join(i, j);
                    found = j;
                    ansMn--;
                    break;
                }
            i = found - 1;
        }

    }

    cout << ansMn << " " << ansMx << endl;
     

}

int32_t main() {
    int ct = 1;
    cin >> ct;
    while(ct--)
        solve();
    return 0;
}