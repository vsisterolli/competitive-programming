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

string s;
int ans = 0;

int visited[8][8];

void backtrack(int x, int y, int mv) {

    if (x == 1 && y == 7) {
        if (mv == 48) ans++;
        return;
    }
    if(visited[x][y])
        return;
    if ((1 - x) + (7 - y) > (48 - mv)) return;
    if( ((visited[x][y+1] && visited[x][y-1]) || y == 1 || y == 7) && (x > 1 && !visited[x - 1][y]) && (x < 7 && !visited[x + 1][y]))
        return;
    if( ((visited[x+1][y] && visited[x-1][y]) || x == 1 || x == 7) && (y > 1 && !visited[x][y - 1]) && (y < 7 && !visited[x][y + 1 ]))
        return;


    visited[x][y] = 1;
    if(s[mv] == '?') {
        if(x < 7)
            backtrack(x + 1, y, mv + 1);
        if(x > 1)
            backtrack(x - 1, y, mv + 1);
        if(y < 7)
            backtrack(x, y + 1, mv + 1);
        if(y > 1)
            backtrack(x, y - 1, mv + 1);
    } else {
        if(s[mv] == 'R') {
            if(x < 7)
                backtrack(x + 1, y, mv + 1);
        }
        if(s[mv] == 'L') {
            if(x > 1)
                backtrack(x - 1, y, mv + 1);
        }
        if(s[mv] == 'D') {
            if(y < 7)
                backtrack(x, y + 1, mv + 1);
        }
        if(s[mv] == 'U') {
            if(y > 1)
                backtrack(x, y - 1, mv + 1);
        }
    }
    visited[x][y] = 0;
    return;
}

int32_t main() {
    FAST;
    cin >> s;
    backtrack(1, 1, 0);
    cout << ans << endl;
}
