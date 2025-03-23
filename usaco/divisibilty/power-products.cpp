#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <chrono>
#define pb push_back
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define endl '\n'
#define ll long long
#define int long long
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
const ll mod = 1e9 + 7, MAXN = 1e5 + 5;
typedef vector<int> vi;
typedef pair<int, pair<int, int>> piii;

int factor[MAXN];

void sieve() {
    for(int i = 2; i < MAXN; i++)
        if(!factor[i])
            for(int j = i; j < MAXN; j += i)
                factor[j] = i;
}

void solve() {
    sieve();
    int n, k;
    cin >> n >> k;

    int pcubes = 0, ans = 0;
    map<vector<pii>, int> ap;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        vector<pii> factorization, invfactorization;
        while(x > 1) {
            int p = factor[x], qtd = 0;
            while(x % p == 0) {
                x /= p;
                qtd++;
            }
            qtd %= k;

            if(!qtd)
                continue;
            factorization.push_back({p, qtd});
            invfactorization.push_back({p, k - qtd});
        }
        if(x > 1) {
            factorization.push_back({x, 1});
            invfactorization.push_back({x, k - 1});
        }

        if(!factorization.size()) 
            ans += pcubes++;

        else {
            ans += ap[invfactorization];
            ap[factorization]++;
        }
    }


    cout << ans << endl;
    

}

int32_t main() {
    FAST;
    int ct = 1;
    // cin >> ct;
    while(ct--)
        solve();
    return 0;
}