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
    int n, m, q;
    cin >> n >> m >> q;

    vector<int> w(n), ap(4097);
    int ans[4100][105];
    memset(ans, -1, sizeof ans);

    for(int &i : w)
        cin >> i;

    for(int i = 0; i < m; i++) {
        string s;
        cin >> s;

        int num = 0;
        for(int j = 0; j < n; j++) 
            num += (s[j] == '1') * (1<<(n - j - 1));
        ap[num]++;
    }


    while(q--) {
        string s;
        int k;

        cin >> s >> k;
        int num = 0;
        for(int j = 0; j < n; j++) 
            num += (s[j] == '1') * (1<<(n - j - 1));

        if(ans[num][k] != -1) {
            cout << ans[num][k] << endl;
            continue;
        }

        for(int i = 0; i <= 100; i++)
            ans[num][i] = 0;
    
        for(int i = 0; i < 4097; i++) {
            int aux = num ^ i;
            int cur = 0;
            for(int j = 0; j < n; j++)
                cur += (!(aux & (1<<j))) * w[n - j - 1]; 

            if(cur <= 100)
                ans[num][cur] += ap[i];
        }
        for(int i = 1; i <= 100; i++)
            ans[num][i] += ans[num][i - 1];
        
        cout << ans[num][k] << endl;

    }
}

int32_t main() {
    int ct = 1;
    FAST;
    // cin >> ct;
    while(ct--)
        solve();
    return 0;
}