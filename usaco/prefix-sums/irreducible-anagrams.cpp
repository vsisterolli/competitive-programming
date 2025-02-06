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
const ll mod = 1e9 + 7, MAXN = 2e5 + 5;
typedef vector<int> vi;
typedef pair<int, pair<int, int>> piii;
// END HEADER

void solve() {
    string s;
    cin >> s;

    int n = s.size();

    int ap[n + 5][26];
    memset(ap, 0, sizeof ap);
    for(int i = 0; i < n; i++) 
        ap[i + 1][s[i] - 'a'] = 1;
    
    for(int i = 2; i <= n; i++) {
        for(int j = 0; j < 26; j++)
            ap[i][j] += ap[i - 1][j];
    }
    int q;
    cin >> q;

    while(q--) {
        int l, r;
        cin >> l >> r;

        if(r - l + 1 == 1 || s[r-1] != s[l-1]) {
            cout << "Yes" << endl;
            continue;
        }

        int deu = 0;
        for(int j = 0; j < 26; j++)
            deu += (ap[r][j] - ap[l - 1][j] > 0);
        
        cout << (deu >= 3 ? "Yes" : "No") << endl;
    }
}

int32_t main() {
    int ct = 1;
    while(ct--) 
        solve();
    
}

