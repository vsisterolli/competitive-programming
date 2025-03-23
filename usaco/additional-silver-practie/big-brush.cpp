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
    int n, m;
    cin >> n >> m;

    vector<vi> mat(n + 5, vi(m + 5));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> mat[i][j];

    int used[n + 5][m + 5], color[n + 5][m + 5];
    memset(used, 0, sizeof used);

    vector<array<int, 3>> ans;
    queue<array<int, 3>> q({{0, 0, 1}, {n - 1, m - 1, -1}});

    while(!q.empty()) {
        array<int, 3> cur = q.front(); q.pop();

        // if(cur[0] + cur[2] < 0 || cur[1] + cur[2] < 0 || cur[0] + cur[2] >= n || cur[1] + cur[2] >= m)
        
        int x[4] = {cur[2], cur[2], 0, 0};
        int y[4] = {0, 0, cur[2], cur[2]};

        if(mat[cur[0]][cur[1]] != color[cur[0]][cur[1]]) {

            if(cur[2] == 1)
                ans.push_back({cur[0] + 1, cur[1] + 1, cur[]})

            else {
                if(cur[0] - 1 < 0 || cur[1] - 1 < 0)
                    continue;
                    
            }


        }
    }
}

int32_t main() {
    int ct = 1;
    // cin >> ct;
    while(ct--)
        solve();
    return 0;
}