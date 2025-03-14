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

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int &i : v)
        cin >> i;

    int x, a;
    cin >> x >> a;

    int y, b;
    cin >> y >> b;

    if(x < y) {
        swap(x, y);
        swap(a, b);
    }

    int k;
    cin >> k;

    sort(all(v), greater<int>());

    int mmc = (a * b)/__gcd(a, b);

    int ini = 1, mid, end = n, ans = n + 1;
    while(ini <= end) {
        mid = (ini + end)/2;
        int cur = 0, curk = 0;
        for(int i = 0; i < mid/mmc; cur++, i++) 
            curk += ((x + y) * v[cur])/100;
        
        for(int i = 0; cur < mid && i < mid/a - mid/mmc; cur++, i++)
            curk += x * v[cur]/100;
        
        for(int i = 0; cur < mid && i < mid/b - mid/mmc; cur++, i++)
            curk += y * v[cur]/100;
    
        if(curk >= k) {
            end = mid - 1;
            ans = min(ans, mid);
        }
        else ini = mid + 1;
    }
    cout << (ans == n + 1 ? -1 : ans) << endl;

}

int32_t main() {
    int ct = 1;
    cin >> ct;
    while(ct--)
        solve();
    return 0;
}