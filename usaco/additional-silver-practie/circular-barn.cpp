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
const ll mod = 1e9 + 7, MAXN = 1005;
typedef vector<int> vi;
typedef pair<int, pair<int, int>> piii;

vector<int> primes;
int dp[MAXN];
bool compound[MAXN];

void sieve() {
    primes.push_back(1);
    for(int i = 2; i < MAXN; i++)
        if(!compound[i]) {
            primes.push_back(i);
            for(int j = i + i; j < MAXN; j+= i)
                compound[j] = 1;
        }
}

void preCompute() {
    for(int &p : primes) 
        dp[p] = 1;
    
    for(int i = 4; i < MAXN; i++) {
        d
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    int besteven = INF, bestodd = INF;
    for(int i = 0; i < n; i++) {
        cin >> v[i];
        debug(dp[v[i]]);
        if(dp[v[i]] & 1)
            bestodd = min(bestodd, dp[v[i]]);
        else
            besteven = min(besteven, dp[v[i]]);
    }

    cout << (bestodd < besteven ? "Farmer John" : "Farmer Nhoj") << endl;
    
}

int32_t main() {
    FAST;
    sieve();
    preCompute();
    int ct = 1;
    cin >> ct;
    while(ct--)
        solve();
    return 0;
}