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
    int n, m, q;
    cin >> n >> m >> q;

    vector<int> a(n), b(m);
    for(int &i : a)
        cin >> i;
    for(int &i : b)
        cin >> i;

    int ka = 0;
    int evenSum = 0, oddSum = 0;
    set<int> sums;
    
    for(int i = 0; i < n; i += 2) {
        ka += a[i];
        oddSum += b[i];
    }
    for(int i = 1; i < n; i += 2) {
        ka -= a[i];
        evenSum += b[i];
    }

    int l = 0, r = n;
    sums.insert(evenSum - oddSum);
    
    while(r < m) {
        oddSum -= b[l++];
        swap(evenSum, oddSum);
        
        if(n & 1)
            oddSum += b[r++];
        else
            evenSum += b[r++];   

        sums.insert(evenSum - oddSum);
    }
    
    int ans = LINF;
    auto aux = sums.lower_bound(-ka);
    if(aux != sums.end()) 
        ans = min(ans, abs(*aux + ka));
    if(aux != sums.begin()) {
        aux--;
        ans = min(ans, abs(*aux + ka));
    }
    cout << ans << endl;

    while(q--) {
        int l, r, x;
        cin >> l >> r >> x;

        if( (r - l + 1) & 1) {
            if(l & 1) ka += x;
            else ka -= x;
        }
        ans = LINF;
        
        auto aux = sums.lower_bound(-ka);
        if(aux != sums.end()) 
            ans = min(ans, abs(*aux + ka));
        if(aux != sums.begin()) {
            aux--;
            ans = min(ans, abs(*aux + ka));
        }
        cout << ans << endl;
    }
}

int32_t main() {
    int ct = 1;
    // cin >> ct;
    while(ct--)
        solve();
    return 0;
}