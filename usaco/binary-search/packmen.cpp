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
    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<int> pack, ast;
    for(int i = 0; i < n; i++) {
        if(s[i] == 'P')
            pack.pb(i);
        if(s[i] == '*')
            ast.pb(i);
    }

    int ini = 1, mid, end = 2 * n + 1, ans = 2 * n + 1;
    while(ini <= end) { 
        mid = (ini + end)/2;
        
        int curast = 0;
        for(int &i : pack) {
            
            if(curast >= ast.size())
                break;
            if(abs(ast[curast] - i) > mid)
                continue;
                
            int xd = curast;
            while(xd < ast.size()) {
                int leftFirst = abs(i - ast[curast]) + abs(ast[curast] - ast[xd]);
                int rightFirst = abs(i - ast[xd]) + abs(ast[xd] - ast[curast]);

                if(min(leftFirst, rightFirst) <= mid)
                    xd++;
                else break;
            }
            curast = xd;

        }

        if(curast == ast.size()) {
            ans = min(ans, mid);
            end = mid - 1;
        } else ini = mid + 1;

    }
    cout << ans << endl;

}

int32_t main() {
    int ct = 1;
    // cin >> ct;
    while(ct--)
        solve();
    return 0;
}