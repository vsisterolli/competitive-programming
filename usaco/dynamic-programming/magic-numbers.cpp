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

struct mint
{
    int x;

    mint(int y=0){x=((y%mod)+mod)% mod;}

    mint operator + (mint y){return {(x+y.x)%mod};}
    mint operator + (int y){return {(x+y)%mod};}
    mint operator - (mint y){return {(x-y.x+mod)%mod};}
    mint operator - (int y){return {(x-y+mod)%mod};}
    mint operator * (mint y){return {(1LL*x*y.x)%mod};}
    mint operator * (int y){return {(1LL*x*y)%mod};}

    void operator += (mint y){x=(x+y.x)%mod;return;}
    void operator += (int y){x=(x+y)%mod;return;}
    void operator -= (mint y){x=(x-y.x+mod)%mod;return;}
    void operator -= (int y){x=(x-y+mod)%mod;return;}
    void operator *= (mint y){x=(1LL*x*y.x)%mod;return;}
    void operator *= (int y){x=(1LL*x*y)%mod;return;}
    
    mint& operator = (mint y){x=y.x;return *this;}
    mint& operator = (int y){x=(y%mod);return *this;}

    bool operator == (mint y){return (x==y.x);}
    bool operator == (int y){return (x==y);}

    bool operator != (mint y){return (x!=y.x);}
    bool operator != (int y){return (x!=y);}
};
ostream& operator<<(ostream& os, mint x) { return os << x.x; }

mint dp[2005][2005][2][2];

void solve() {
    int N, d;
    cin >> N >> d;

    string a, b;
    cin >> a >> b;
    int n = a.size(), m = b.size();

    memset(dp, 0, sizeof dp);
    int pot[m + 1];
    pot[m - 1] = 1; 


    dp[0][0][0][0] = 1;
    for(int i = 0; i < m; i++) 
        for(int md = 0; md < N; md++)
            for(int flag1 = 0; flag1 <= 1; flag1++)
                for(int flag2 = 0; flag2 <= 1; flag2++) 
                    for(int j = !i; j <= 9; j++) {
                        if(!flag1 && j > (b[i] - '0'))
                            continue;
                        if(!flag2 && j < (a[i] - '0'))
                            continue; 

                        if(j == d && ((i + 1) % 2 == 1) )
                            continue;
                        if(j != d && ((i + 1) % 2 == 0) )
                            continue;

                        int nflag1 = (flag1 | j < (b[i] - '0'));
                        int nflag2 = (flag2 | j > (a[i] - '0'));

                        dp[i + 1][(md * 10 + j)%N][nflag1][nflag2] += dp[i][md][flag1][flag2];
                    }
                    

    cout << dp[m][0][0][0] + dp[m][0][0][1] + dp[m][0][1][0] + dp[m][0][1][1] << endl;

    



}

int32_t main() {
    FAST;
    int ct = 1;
    // cin >> ct;
    while(ct--)
        solve();
    return 0;
}