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


int dp[20][2][2];
string dp2[21][2][2];

void solve() {
    string a, b;
    cin >> a >> b;

    int m = b.size(), n = a.size();
    memset(dp, -1, sizeof dp);
    dp[0][0][0] = 1;    
    dp2[0][0][0] = "";

    for(int i = 0; i < m; i++) 
        for(int flag1 = 0; flag1 <= 1; flag1++)
            for(int flag2 = 0; flag2 <= 1; flag2++) 
                for(int j = 0; j <= 9; j++) {
                    if(!flag1 && j > (b[i] - '0'))
                        continue;
                    if(dp[i][flag1][flag2] == -1)
                        continue;
                    int apos = i -m + n;
                    if(!flag2 && j < (apos < 0 ? 0 : (a[apos] - '0')) )
                        continue; 

                    int nflag1 = (flag1 | j < (b[i] - '0'));
                    int nflag2 = (flag2 | apos < 0 || (apos >= 0 && j > (a[apos] - '0') ));

                    int multp = j;
                    if(!j && (!i && m > n))
                        multp = 1;

                    if(dp[i][flag1][flag2] * multp >= dp[i + 1][nflag1][nflag2]) {
                        dp[i + 1][nflag1][nflag2] = dp[i][flag1][flag2] * multp;
                        if(j == multp) {
                            string aux = dp2[i][flag1][flag2];
                            aux.push_back(j + '0');
                            dp2[i + 1][nflag1][nflag2] = aux;
                        }
                        else dp2[i + 1][nflag1][nflag2] = dp2[i][flag1][flag2];
                    }

                }

    int best = -1;
    string bests = "";
    for(int flag1 = 0; flag1 <= 1; flag1++)
        for(int flag2 = 0; flag2 <= 1; flag2++) {
            if(dp[m][flag1][flag2] > best ) {
                best = dp[m][flag1][flag2];
                bests = dp2[m][flag1][flag2];
            }
        }
    cout  << bests << endl;
}

int32_t main() {
    int ct = 1;
    // cin >> ct;
    while(ct--)
        solve();
    return 0;
}