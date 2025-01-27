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
typedef vector<vector<char>> mt;
typedef pair<int, string> pis;
const ll mod = 1e9 + 7, MAXN = 2e5 + 5;
typedef vector<int> vi;
typedef pair<int, pair<int, int>> piii;
// END HEADER

char mat[8][8];
vector<int> line(8), col(8);
int ans = 0;

void solve(int i, int j, int tot) {
    if(tot == 8) {
        ans++;
        return;
    }

    if(i == 8 && j == 0)
        return;

    if(mat[i][j] != '*' && !line[i] && !col[j]) {
        bool na = false;
        for(int k = 1; i - k >= 0 && (j + k <= 7 || j - k >= 0); k++) {
            if(i - k >= 0 && k + j <= 7)
                na |= (mat[i - k][k + j] == 'Q');
            if(i - k >= 0 && j - k >= 0)
                na |= (mat[i - k][j - k] == 'Q');
            if(na)
                break;
        }

        if(!na) {
            char current = mat[i][j];
            mat[i][j] = 'Q';
            line[i] = col[j] = 1;
            if(j == 7)
                solve(i+1, 0, tot + 1);
            else
                solve(i, j+1, tot + 1);
            mat[i][j] = current;
            line[i] = col[j] = 0;
        }

    }
    if(j == 7)
        solve(i + 1, 0, tot);
    else
        solve(i, j+1, tot);
}

int32_t main() {
    for(int i = 0; i < 8; i++)
        for(int j = 0; j < 8; j++)
            cin >> mat[i][j];
    solve(0, 0, 0);

    cout << ans << endl;
}

