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

using cd = complex<double>;
const double PI = acos(-1);

void fft(vector<cd> & a, bool invert) {
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
        double ang = 2 * PI / len * (invert ? -1 : 1);
        cd wlen(cos(ang), sin(ang));
        for (int i = 0; i < n; i += len) {
            cd w(1);
            for (int j = 0; j < len / 2; j++) {
                cd u = a[i+j], v = a[i+j+len/2] * w;
                a[i+j] = u + v;
                a[i+j+len/2] = u - v;
                w *= wlen;
            }
        }
    }

    if (invert) {
        for (cd & x : a)
            x /= n;
    }
}

vector<int> multiply(vector<int> const& a, vector<int> const& b) {
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < a.size() + b.size())
        n <<= 1;
    fa.resize(n);
    fb.resize(n);

    fft(fa, false);
    fft(fb, false);
    for (int i = 0; i < n; i++)
        fa[i] *= fb[i];
    fft(fa, true);

    vector<int> result(n);
    for (int i = 0; i < n; i++)
        result[i] = round(fa[i].real());
    return result;
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    
    vector<vector<int>> ap(4, vector<int>(n)), apt(4, vector<int>(m));

    string s, t;
    cin >> s >> t;
    for(int i = 0; i < n; i++) {
        if(s[i] == 'A') {
            ap[0][i]++;
            if(i + k + 1 < n)
                ap[0][i + k + 1]--;
        }
        else if(s[i] == 'G') {
            ap[1][i]++;
            if(i + k + 1 < n)
                ap[1][i + k + 1]--;
        }
        else if(s[i] == 'C') {
            ap[2][i]++;
            if(i + k + 1 < n)
                ap[2][i + k + 1]--;
        }
        else {
            ap[3][i]++;
            if(i + k + 1 < n)
                ap[3][i + k + 1]--; 
        }

        for(int j = 0; j <= 3; j++) 
            if(i + 1 < n)
                ap[j][i + 1] += ap[j][i];
    }

    
    for(vi &i : ap)
        for(int j = 0; j < i.size(); j++) {
            i[j] = max(i[j], i[min((int)i.size() - 1, j + k)]);
            i[j] = min(1, i[j]);
        }
    
    for(int i = 0; i < m; i++) {
        if(t[i] == 'A')
            apt[0][i]++;
        else if(t[i] == 'G')
            apt[1][i]++;
        else if(t[i] == 'C')
            apt[2][i]++;
        else
            apt[3][i]++;    
    }

    reverse(all(apt[0])); reverse(all(apt[1])); reverse(all(apt[2])); reverse(all(apt[3]));
    ap[0] = multiply(ap[0], apt[0]);
    ap[1] = multiply(ap[1], apt[1]);
    ap[2] = multiply(ap[2], apt[2]);
    ap[3] = multiply(ap[3], apt[3]);

    int ans = 0;
    for(int i = m - 1; i < (n - m) + m; i++) {
        debug4(ap[0][i], ap[1][i], ap[2][i], ap[3][i]); 
        if(ap[0][i] + ap[1][i] + ap[2][i] + ap[3][i] == m)
            ans++;

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