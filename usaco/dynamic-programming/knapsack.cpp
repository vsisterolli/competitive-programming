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
typedef pair<int, int> pii;
typedef vector<vector<char>> mat;
typedef pair<int, string> pis;
const ll mod = 1e9 + 7, MAXN = 2e5 + 5;
typedef vector<int> vi;
typedef pair<int, pair<int, int>> piii;

int dp[2][2005], cnt[2005], ans = 0;
vector<pii> ri;
vector<int> items[2001];

void solve() {
    int n, s;
    int v, w, k;
    cin >> s >> n;

    vector<array<int, 3>> poss;
    for(int i = 0; i < n; i++) {
        cin >> v >> w >> k;
        poss.push_back({v, w, k});
    }

    sort(all(poss), greater<array<int, 3>>());
    for(auto &i : poss) 
        for(int j = 0; j < i[2]; j++) {
            if(cnt[i[1]] >= s/i[1])
                break;

            cnt[i[1]]++;
            ri.push_back({i[0], i[1]});
        }
    

    for(int i = 0; i < ri.size(); i++) {
        for(int j = s; j >= 0; j--) {
            if(!i && j >= ri[i].s)
                dp[i][j] = ri[i].f;
            
            else if(i) {
                dp[i & 1][j] = dp[!(i & 1)][j];
                if(j >= ri[i].s)
                    dp[i & 1][j] = max(dp[i & 1][j], dp[!(i & 1)][j - ri[i].s] + ri[i].f);
            }
            ans = max(ans, dp[i & 1][j]);
        }
    }
    cout << ans << endl;
}

int32_t main() {
    solve();
    return 0;
}