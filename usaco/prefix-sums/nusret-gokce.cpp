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
#define int long long
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
const ll mod = 2019, MAXN = 2e5 + 5;
typedef vector<int> vi;
typedef pair<int, pair<int, int>> piii;
// END HEADER

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> v(n);
    priority_queue<pii> fila;
    for(int i = 0; i < n; i++) {
        cin >> v[i];
        fila.push({v[i], i});
    }

    while(!fila.empty()) {
        pii aux = fila.top();
        fila.pop();

        if(aux.s + 1 < n && v[aux.s] - v[aux.s + 1] > m) {
            fila.push({v[aux.s] - m, aux.s+1});
            v[aux.s + 1] = v[aux.s] - m;
        }

        if(aux.s - 1 >= 0 && v[aux.s] - v[aux.s - 1] > m) {
            fila.push({v[aux.s] - m, aux.s-1});
            v[aux.s - 1] = v[aux.s] - m;
        }
    }

    for(int &i : v)
        cout << i << " ";
    cout << endl;
}

int32_t main() {
    int ct = 1;
    while(ct--) 
        solve();   
}