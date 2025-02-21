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
    int xs, ys, xg, yg;
    cin >> xs >> ys >> xg >> yg;
    
    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<int> sx(n + 1), sy(n + 1);
    for(int i = 0; i < n; i++) {
        if(s[i] == 'U')
            sy[i+1]++;
        if(s[i] == 'D')
            sy[i+1]--;
        if(s[i] == 'L')
            sx[i+1]--;
        if(s[i] == 'R')
            sx[i+1]++;

        sx[i+1] += sx[i];
        sy[i+1] += sy[i];
    }

    int ini = 0, mid, end = 1e16, ans = 1e17;
    while(ini <= end) {
        mid = (ini + end)/2;

        int curx = xs + mid/n * sx[n] + sx[mid % n];
        int cury = ys + mid/n * sy[n] + sy[mid % n];
        
        if( abs(curx - xg) + abs(cury - yg) <= mid ) {
            ans = min(ans, mid);
            end = mid - 1;
        }
        else ini = mid + 1;
    }   

    cout << (ans == (int)1e17 ? -1 : ans) << endl;

}

int32_t main() {
    int ct = 1;
    // cin >> ct;
    while(ct--)
        solve();
    return 0;
}