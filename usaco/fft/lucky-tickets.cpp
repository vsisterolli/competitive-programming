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
const ll mod = 998244353, MAXN = 2e5 + 5;
typedef vector<int> vi;
typedef pair<int, pair<int, int>> piii;

ll W1;

int powmod (int a, int b, int p) {
    int res = 1;
    while (b)
        if (b & 1)
            res = (res * 1ll * a % p),  --b;
            else
            a = (a * 1ll * a % p),  b >>= 1;
            return res;
}

int generator (int p) {
    vector<int> fact;
    int phi = p-1,  n = phi;
    for (int i=2; i*i<=n; ++i)
    if (n % i == 0) {
            fact.push_back (i);
            while (n % i == 0)
            n /= i;
        }
    if (n > 1)
    fact.push_back (n);

    for (int res=2; res<=p; ++res) {
        bool ok = true;
        for (size_t i=0; i<fact.size() && ok; ++i)
            ok &= powmod (res, phi / fact[i], p) != 1;
        if (ok)  return res;
    }
    return -1;
}

const ll root = 15311432;
const ll root_1 = 469870224;
const ll root_pw = 1 << 23;

void fft(vector<int> & a, bool invert) {
    int n = a.size();

    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;

        if (i < j)
            swap(a[i], a[j]);
    }

    for (int len = 2; len <= n; len <<= 1) {
        int wlen = invert ? root_1 : root;
        for (int i = len; i < root_pw; i <<= 1)
            wlen = (int)(1LL * wlen * wlen % mod);

        for (int i = 0; i < n; i += len) {
            int w = 1;
            for (int j = 0; j < len / 2; j++) {
                int u = a[i+j], v = (int)(1LL * a[i+j+len/2] * w % mod);
                a[i+j] = u + v < mod ? u + v : u + v - mod;
                a[i+j+len/2] = u - v >= 0 ? u - v : u - v + mod;
                w = (int)(1LL * w * wlen % mod);
            }
        }
    }

    if (invert) {
        int n_1 = powmod(n, mod - 2, mod);
        for (int & x : a)
            x = (int)(1LL * x * n_1 % mod);
    }
}

vector<int> multiply(vector<int> const& a, vector<int> const& b) {
    vector<int> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < a.size() + b.size())
        n <<= 1;
    fa.resize(n);
    fb.resize(n);

    fft(fa, false);
    fft(fb, false);
    for (int i = 0; i < n; i++)
        fa[i] = (fa[i] * fb[i])%mod;
    fft(fa, true);

    return fa;
}

int32_t main() {
    FAST;
    int g = generator(mod);

    int c = mod - 1;
    while(c % 2 == 0)
        c >>= 1;

    int n, k;
    cin >> n >> k;
    vector<int> v(11);
    for(int i = 0; i < k; i++) {
        int x;
        cin >> x;
        v[x] = 1;
    }
    n /= 2;

    vector<int> poly, ans;
    for(int i = 0; i < 10; i++)
        poly.push_back(v[i]);
            
    int sum = 0, cur = 1;
    while(sum != n) {
        
        if(n & cur) {
            sum += cur;
            if(!ans.size()) 
                ans = poly;
            else ans = multiply(ans, poly);
        }
        
        cur <<= 1;
        vector<int> helper(all(poly));
        poly = multiply(helper, poly);
    }

    int tans = (ans[0] > 0);
    for(int i = 1; i < ans.size(); i++)
        tans = (tans + (ans[i] * ans[i])%mod)%mod;
    cout << tans << endl;
}