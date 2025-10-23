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
const ll mod = 1e9 + 7, MAXN = 1e3 + 5;
typedef vector<int> vi;
typedef pair<int, pair<int, int>> piii;

vector<int> lp(MAXN);

void sieve() {
    vector<int> primes;
    for(int i = 2; i < MAXN; i++) {
        if(!lp[i]) {
            lp[i] = i;
            primes.push_back(i);
        }

        for(int &j : primes) {
            if(j * i >= MAXN)
                break;

            lp[j * i] = j;
            if(lp[i] == j)
                break;
        }
    }
}

long double modExpo(long double a, ll p) {
    long double ans = 1.0;
    while(p) {
        if(p & 1)
            ans = (ans * a);
        a = a * a;
        p >>= 1;
    }
    return ans;
}

void solve() {
    int t, k;
    cin >> t >> k;

    t--;

    long double PL = 0.5;

    auto Cprobability = [&](int n, int k) -> long double {
        int count = 0;
        long double P = 1.0;
        if(n < 0 || k < 0 || k > n)
            return 0.0;

        vector<int> factors(n + 1);
        for(int i = 1; i <= n; i++) {
            int aux = i;
            while(aux > 1) {
                factors[lp[aux]]++;
                aux /= lp[aux];
            }
        }

        for(int i = 1; i <= n - k; i++) {
            int aux = i;
            while(aux > 1) {
                factors[lp[aux]]--;
                aux /= lp[aux];
            }
        }

        for(int i = 1; i <= k; i++) {
            int aux = i;
            while(aux > 1) {
                factors[lp[aux]]--;
                aux /= lp[aux];
            }
        }

        factors[2] -= n;
        for(int i = 3; i <= n; i++) 
            while(factors[i]) {
                P *= i;
                factors[i]--;
                while(P >= 1e15 && factors[2] < 0) {
                    P /= 2.0;
                    factors[2]++;
                }
            }
        
        while(factors[2] < 0) {
            P /= 2.0;
            factors[2]++;
        }

        return P;
    };

    if(!(t & 1)) 
        PL -= Cprobability(t, t/2)/2.0;

    int EV = t/2;

    long double ans = 0;
    long double an = modExpo(PL, k);
    for(int i = 1; i <= t; i++) {
        if(i <= EV) {
            ans += i * Cprobability(t, i) * modExpo(PL, k - 1);
        }
        else {
            ans += i * Cprobability(t, i) * (an - 1.0) / (PL - 1.0);
        }
    }
    cout << fixed << setprecision(8) << ans + 1.0 << endl;
}

int32_t main() {
    sieve();
    int ct = 1;
    // cin >> ct;
    while(ct--)
        solve();
    return 0;
}