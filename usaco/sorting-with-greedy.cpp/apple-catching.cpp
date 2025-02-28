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

typedef struct item {
    int q, t, x, n;
    bool operator<(item &a) {
        if(x - t != a.x - a.t)
            return x - t < a.x - a.t;
        return q > a.q;
    }
    item() {};
} item;

void solve() {
    int n;
    cin >> n;

    vector<item> items(n);
    for(item &i : items) 
        cin >> i.q >> i.t >> i.x >> i.n;
    sort(all(items));

    multiset<pii> cows;
    int ans = 0;

    for(item &i : items) {
        if(i.q == 2)
            cows.insert({i.x + i.t, i.n});
        
        else {

            while(i.n) {
                auto bestCowPtr = (cows.lb({i.x + i.t, 0}));
                if(bestCowPtr == cows.end())
                    break;
                
                cows.erase(bestCowPtr);

                pii bestCow = *bestCowPtr;
                int trmv = min(i.n, bestCow.s);
                bestCow.s -= trmv;
                i.n -= trmv;
                ans += trmv;

                if(bestCow.s)
                    cows.insert(bestCow);
            }

        }
    }
    cout << ans << endl;
}

int32_t main() {
    int ct = 1;
    // cin >> ct;
    while(ct--)
        solve();
    return 0;
}