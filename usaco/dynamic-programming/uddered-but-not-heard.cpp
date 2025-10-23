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
typedef pair<ll, ll> pii;
typedef vector<vector<char>> mat;
typedef pair<int, string> pis;
const ll mod = 1e9 + 7, MAXN = 2e5 + 5;
typedef vector<int> vi;
typedef pair<int, pair<int, int>> piii;

void solve() {
    string s;
    cin >> s;

    vector<int> used(26, -1);
    unordered_map<int, short int> rbit;
    int cnt = 0;
    for(int i = 0; i < s.size(); i++)  {
        s[i] -= 'a';
        if(used[s[i]] == -1) {
            used[s[i]] = cnt;
            cnt++;
        }
    }

    for(int i = 1, j = 0; j <= 20; j++, i <<=1) 
        rbit[i] = j;
            
    vector<vector<int>> table(26, vector<int>(26));
    for(int i = 1; i < s.size(); i++) 
        table[used[s[i - 1]]][used[s[i]]]++;
    
    int mx = (1<<cnt);
    vector<int> dp(mx);
    for(int i = 1; i < mx; i++) {
        dp[i] = 1e9;
        
        int aux = i;
        while(aux) {
            int bit = (aux & -(aux));
            aux -= bit;
            int rbitted = rbit[bit];

            int cnt = 0;

            int aux2 = i;
            while(aux2) {
                int bit2 = (aux2 & (-aux2));
                aux2 -= bit2;
                bit2 = rbit[bit2];
                cnt += table[rbitted][bit2];
            }
            dp[i] = min(dp[i], dp[i ^ bit] + cnt);
        }
    }
    cout << dp[mx - 1] + 1 << endl;
}

int32_t main() {
    FAST;
    int ct = 1;
    // cin >> ct;
    while(ct--)
        solve();
    return 0;
}