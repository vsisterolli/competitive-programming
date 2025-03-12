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

map<int, int> exists;

void solve() {
    int n, c;
    cin >> n >> c;
    
    vector<int> v(c);
    vector<int> dist(262144, INF);
    queue<int> q;

    for(int i = 0; i < c; i++) {
        string s;
        cin >> s; 
        for(int j = 0; j < n; j++) {
            if(s[j] == 'G')
                v[i] ^= (1<<(n - j - 1));
        }
        q.push(v[i]);
        dist[v[i]] = 0;
    }

    while(!q.empty()) {
        int u = q.front();
        q.pop();

        for(int i = 0; i < n; i++) {
            int nxt = u ^ (1<<(n - i - 1));
            if(dist[u] + 1 < dist[nxt]) {
                dist[nxt] = dist[u] + 1;
                q.push(nxt);
            }
        }
    }
        
    for(int &i : v) {
        int allOn = (1<<n) - 1;
        cout << n - dist[allOn ^ i] << endl;
    }

}

int32_t main() {
    int ct = 1;
    // cin >> ct;
    while(ct--)
        solve();
    return 0;
}