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
    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<int> poly1, poly2, qint(n + 1);
    for(int i = 0; i < n; i++) {
        poly1.push_back( (s[i] == '?') || (s[i] == 'K') );
        poly2.push_back( (s[i] == '?') || (s[i] == 'K'));
    }   

    reverse(all(poly1));
    vector<int> ans = multiply(poly1, poly2);
    
    poly1.clear();
    poly2.clear();

    for(int i = 0; i < n; i++) {
        poly1.push_back( (s[i] == '?') || (s[i] == 'V'));
        poly2.push_back( (s[i] == '?') || (s[i] == 'V'));
    }
    reverse(all(poly1));
    poly1 = multiply(poly1, poly2);

    for(int i = 0; i < poly1.size(); i++)
        ans[i] += poly1[i];

    poly1.clear();
    poly2.clear();    

    for(int i = 0; i < n; i++) {
        poly1.push_back( (s[i] == '?') );
        poly2.push_back( (s[i] == '?') );
    }
    reverse(all(poly1));
    poly1 = multiply(poly1, poly2);

    for(int i = 0; i < poly1.size(); i++)
        ans[i] -= poly1[i];

    
    vector<int> ansx;
    vector<int> valid(n + 1);

    for(int j = 2 * n - 1; j >= n; j--) { 
        int k = j - n + 1;
        bool cur = (ans[j] == n - k);
        for(int x = k + k; x <= n; x += k) 
            cur &= valid[x];
        
        if(cur)
            ansx.push_back(k);
        valid[k] = cur;
    }

    reverse(all(ansx));
    cout << ansx.size() << endl;
    for(int &i : ansx)
        cout << i << " ";
    cout << endl;
}

int32_t main() {
    int ct = 1;
    cin >> ct;
    while(ct--)
        solve();
    return 0;
}