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

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> v(n), ap(MAXN + 1);
    vector<ll> sap(MAXN + 1);
    for(int &i : v) {
        cin >> i;
        ap[i]++;
        sap[i] += i;
    }

    sort(all(v), greater<int>());
    for(int i = 1; i < MAXN; i++) {
        ap[i] += ap[i - 1];
        sap[i] += sap[i - 1];
    }
    
    int ini = 1, mid, end = 2e5, ans = 2;
    while(ini <= end) {
        mid = (ini + end)/2;

        int tot = 0;
        for(int i = 0; i < n; i++) {
            if(v[i] >= mid)
                tot += n;
            else
                tot += ap[MAXN - 1] - ap[mid - v[i] - 1];
        }

        if(tot >= k) {
            ans = max(ans, mid);
            ini = mid + 1;
        }
        else end = mid - 1;
        
    }

    ll sum = 0;
    for(int i = 0; k && i < n; i++)  {
        
        int ini = 0, mid, end = MAXN - 1, ans = -1;
        while(ini <= end) {
            mid = (ini + end)/2;

            if(ap[MAXN - 1] - (v[i] >= mid ? 0 : ap[ans - v[i] - 1]) <= k){
                ans = max(ans, )
            }

        }

    }

    cout << sum << endl;

}

int32_t main() {
    FAST;
    int ct = 1;
    // cin >> ct;
    while(ct--)
        solve();
    return 0;
}