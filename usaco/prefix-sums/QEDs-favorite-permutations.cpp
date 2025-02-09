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
// END HEADER

void solve() {
    int n, q;
    cin >> n >> q;

    vector<int> v(n+1), aux(n+5);
    for(int i = 1; i <= n; i++) {
        cin >> v[i];
        if(v[i] != i) {
            aux[min(v[i], i)]++;
            aux[max(v[i], i) + 1]--;
        }
    }

    vector<int> ls, rs, tot;
    
    int l = 0;
    for(int i = 1; i <= n; i++) {
        aux[i + 1] += aux[i];
        if(!aux[i] && l) {
            assert(l != i - 1);
            ls.pb(l);
            rs.pb(i - 1);
            l = 0;
        }
        if(aux[i] && !l)
            l = i;
    }

    if(l) {
        ls.pb(l);
        rs.pb(n);
    }

    vector<char> s(n+5);
    for(int i = 1; i <= n; i++)
        cin >> s[i];

    int canI = 0;
    for(int i = 0; i < (int)ls.size(); i++) {
        int aux = 0;
        for(int j = ls[i]; j + 1 <= rs[i]; j++) 
            if(s[j] == 'L' && s[j+1] == 'R')
                aux++;
        
        tot.pb(aux);
        canI += (aux > 0);
    }

    while(q--) {
        int x;
        cin >> x;

        int ini = 0, mid, end = ls.size() - 1, ans = -1;
        while(ini <= end) {
            mid = (ini + end)/2;
            if(x >= ls[mid] && x <= rs[mid]) {
                ans = mid;
                break;
            }
            else if(x > rs[mid])
                ini = mid + 1;
            else end = mid - 1;
        }

        if(ans == -1) {
            cout << (!canI ? "YES" : "NO") << endl;
            continue;
        }

        canI -= (tot[ans] > 0);
        if(s[x] == 'L') {

            if(x + 1 <= rs[ans] && s[x + 1] == 'R')
                tot[ans]--;

            if(x - 1 >= ls[ans] && s[x - 1] == 'L')
                tot[ans]++;

            s[x] = 'R';
        } else {
            
            if(x + 1 <= rs[ans] && s[x + 1] == 'R')
                tot[ans]++;
            
            if(x - 1 >= ls[ans] && s[x - 1] == 'L')
                tot[ans]--;

            s[x] = 'L';

        }
        canI += (tot[ans] > 0);
        

        cout << (!canI ? "YES" : "NO") << endl;
    }

}

int32_t main() {
    int ct;
    cin >> ct;
    while(ct--)
        solve();
}

