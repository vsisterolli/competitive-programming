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

int32_t main() {
    int n, k;
    cin >> n >> k;
    
    vector<int> poly(1002);
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        poly[x] = 1;
    }
    
    int big, mn;
    for(int i = poly.size() - 1; i >= 0; i--) 
        if(poly[i] == 1) {
            big = i;
            break;
        }
    for(int i = 0; i < poly.size(); i++)
        if(poly[i]) {
            mn = i;
            break;
        }
    poly.resize(big + 1);

    vector<int> ans;
    int p = 1, rk = k, sum = 0;
    while(k) {
        if(k & 1) {
            sum += p;
            if(!ans.size()) 
                ans = poly;
            else {
                ans = multiply(ans, poly);  
                if(ans.size() > sum * big + 1) {
                    ans.resize(sum * big + 1);
                    for(int i = sum * big + 1; i < ans.size(); i++) 
                        ans[i] = 0;
                    for(int i = 0; i < ans.size(); i++)
                        ans[i] = (ans[i] > 0);
                }

            }
        }

        vector<int> aux(all(poly));
        poly = multiply(poly, aux);
        
        p *= 2;
        for(int i = p * big + 1; i < poly.size(); i++)
            poly[i] = 0;
        for(int i = 0; i < poly.size(); i++)
            poly[i] = (poly[i] > 0);
        poly.resize(p * big + 1);

        k >>= 1;
    }

    for(int i = rk * mn; i < ans.size(); i++)
        if(ans[i]) 
            cout << i << " ";

    cout << endl;
    return 0;
}