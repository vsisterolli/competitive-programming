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
using cd = complex<double>;
typedef vector<vector<char>> mat;
typedef pair<int, string> pis;
const ll mod = 1e9 + 7, MAXN = 2e5 + 5;
typedef vector<int> vi;
typedef pair<int, pair<int, int>> piii;
 
void merge(vector<cd> &E, vector<cd> &O, vector<cd> &A) {
    const double pi = acos(-1);
    const int m = A.size();
 
    cd i(0.0, 1.0);
    cd W1 = exp(-2.0 * pi * i / static_cast<double>(m));
    cd W = 1;
 
    for(int j = 0; j < m/2; j++) {
        A[j] = E[j] + W * O[j];
        A[j + m/2] = E[j] - W * O[j];
        W *= W1;
    }
}
 
void fft(vector<cd> &a) {
    int m = a.size();
    if(a.size() == 1) 
        return;
 
    vector<cd> v1, v2;
    for(int i = 0; i < m; i += 2)
        v1.push_back(a[i]);
    for(int i = 1; i < m; i += 2)
        v2.push_back(a[i]);
 
    fft(v1), fft(v2);
    merge(v1, v2, a);
}
 
vector<int> multiply(vector<int> ia, vector<int> ib) {
    assert(ia.size() == ib.size());
    vector<cd> a(ia.begin(), ia.end()), b(ib.begin(), ib.end());
 
    int m = 1;
    while(m < a.size() + b.size())
        m <<= 1;
 
    a.resize(m);
    b.resize(m);
 
    fft(a);
    fft(b);
    
    for(int i = 0; i < m; i++) 
        a[i] *= b[i];
    fft(a);
 
    reverse(a.begin() + 1, a.end());
 
    vector<int> ans;
    
    for(cd &i : a) {
        i /= m;
        ans.push_back(round(i.real()));
    }
 
    return ans;
}
 
int32_t main() {
    int n, m, k;
    cin >> k >> n >> m;
 
    vector<int> a(MAXN), b(MAXN);
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[x] += 1;
    }
    for(int i = 0; i < m; i++) {
        int x;
        cin >> x;
        b[x] += 1;
    }
 
    vector<int> ans = multiply(a, b);
    for(int i = 2; i <= 2 * k; i++)
        cout << ans[i] << " ";
    cout << endl;
}
