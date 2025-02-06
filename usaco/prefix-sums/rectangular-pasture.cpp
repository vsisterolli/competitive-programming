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
    int n;
    cin >> n;

    N = n;

    vector<pii> v(n);
    vector<int> aux;
    for(pii &i : v) {
        cin >> i.f >> i.s;
        aux.pb(i.s);
    }

    sort(aux.begin(), aux.end());

    for(int i = 0; i < n; i++) 
        for(int j = 0; j < n; j++)
            if(v[j].s == aux[i]) {
                v[j].s = i;
                break;
            }
    sort(v.begin(), v.end());


    // sum[i][j] -> quantos números <= j se eu considero os primeiros i elementos
    
    int sum[n][n];
    memset(sum, 0, sizeof sum);
    for(int i = 0; i < n; i++)
        sum[i][v[i].s] = 1;
    
    for(int i = 0; i < n; i++) {
        for(int j = 1; j < n; j++) 
            sum[i][j] += sum[i][j - 1];

        if(i)
            for(int j = 0; j < n; j++) 
                sum[i][j] += sum[i - 1][j];
    }

    int ans = 0;
    for(int i = 0; i < n; i++) {
        
        for(int j = i; j < n; j++) {
            int mn = sum[j][min(v[i].s, v[j].s)] - (!i ? 0 : sum[i - 1][min(v[i].s, v[j].s)]);
            int mx = (sum[j][n - 1] - sum[j][max(v[j].s, v[i].s) - 1]) - (!i ? 0 : sum[i - 1][n - 1] - sum[i - 1][max(v[j].s, v[i].s) - 1]);

            ans += mn * (i == j ? 1 : mx);
        }
    }
    cout << ans+1 << endl;
}

int32_t main() {
    int ct = 1;
    while(ct--) 
        solve();   
}