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


void merge(vector<int> &E, vector<int> &O, vector<int> &A) {
    const int m = A.size();

    int root = powmod(3, (mod - 1) / m, mod); 

    int W = 1;
    for(int j = 0; j < m/2; j++) {
        A[j] = (E[j] + W * O[j])%mod;
        A[j + m/2] = (E[j] - W * O[j])%mod; 
        if(A[j + m/2] < mod)
            A[j + m/2] += mod;

        W = (W * root)%mod;
    }
}

void fft(vector<int> &a) {
    int m = a.size();
    if(a.size() == 1) 
        return;

    vector<int> v1, v2;
    for(int i = 0; i < m; i += 2)
        v1.push_back(a[i]);
    for(int i = 1; i < m; i += 2)
        v2.push_back(a[i]);

    fft(v1), fft(v2);
    merge(v1, v2, a);
}

vector<int> multiply(vector<int> a, vector<int> b) {
    int m = 1;
    while(m < a.size() + b.size())
        m <<= 1;

    a.resize(m);
    b.resize(m);

    fft(a);
    fft(b);
    
    for(int i = 0; i < m; i++)
        a[i] = (a[i] * b[i])%mod;
    fft(a);

    reverse(a.begin() + 1, a.end());

    int inv_m = powmod(m, mod - 2, mod);
    for(int &i : a)
        i = (i * inv_m)%mod;
    
    return a;
}

int32_t main() {
    int g = generator(mod);

    int c = mod - 1;
    while(c % 2 == 0)
        c >>= 1;
    W1 = powmod(g, c, mod);

    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(m);
    for(int &i : a)
        cin >> i;
    for(int &i : b)
        cin >> i;

    vector<int> F = multiply(a, b);
    for(int i = 0; i + 1 < n + m; i++)
        cout << F[i] << " ";
    cout << endl;   

}