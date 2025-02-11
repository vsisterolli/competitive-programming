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


int aux[MAXN];

void sieve() {
    for(int i = 2; i < MAXN; i++)
        if(!aux[i])
            for(int j = i; j < MAXN; j += i)
                if(!aux[j])
                    aux[j] = i;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> v(m);
    for(int &i : v)
        cin >> i;

    vector<int> ans(n + 1);
    sort(v.begin(), v.end(), greater<int>());

    for(int i = 2; i <= n; i++) {
        if(!aux[i])
            ans[i] = 1;
        else
            ans[i] = ans[i/aux[i]] + 1;
        
        if(ans[i] >= m) {
            cout << -1 << endl;
            return;
        }
    }

    for(int i = 1; i <= n; i++)
        cout << v[ans[i]] << " ";
    cout << endl;
}

int32_t main() {
    int ct = 1;
    sieve();
    
    cin >> ct;
    while(ct--)
        solve();
}