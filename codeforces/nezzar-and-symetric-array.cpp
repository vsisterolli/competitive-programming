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

void solve() {
    int n;
    cin >> n;
    n *= 2;

    vector<ll> v(n), posi;
    map<ll, int> count;
    for(ll &i : v) {
        cin >> i;
        count[i]++;
    }

    for(auto &i : count) {
        if(i.s & 1) {
            cout << "NO" << endl;
            return;
        }

        for(int j = 0; 2 * j < i.s; j++)
            posi.pb(i.f);
    }
    sort(all(posi), greater<ll>());
    
    ll aux = 0, sum = 0;
    map<ll, bool> cnt2;
    
    for(int i = 0; 2 * i < n; i++) {
        if( (-posi[i] - 2 * sum) % (n - 2 * i) ) {
            cout << "NO" << endl;
            return;
        }

        ll ai = (-posi[i] - 2 * sum)/(n - 2 * i);
        if(ai >= 0 || cnt2[ai]) {
            cout << "NO" << endl;
            return;
        }

        cnt2[ai] = 1;
        sum += ai;
    }

    cout << "YES" << endl;

}

int32_t main() {
    int ct = 1;    
    cin >> ct;
    while(ct--)
        solve();
}