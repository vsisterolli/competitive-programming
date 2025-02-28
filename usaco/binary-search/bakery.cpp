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

vector<tuple<int, int, int>> clients;
int n, tc, timem;

int f(int mid) {
    int mn = timem, deu = true;
    for(auto i : clients) {
        auto [cookies, muffins, time] = i;
        
        if(time <= cookies * mid) {
            deu = false;
            continue;
        }
        
        int x = (time - cookies * mid)/muffins;
        mn = min(x, mn);
    }

    if(!deu)
        return LLONG_MAX;
    else return (tc - mid) + (timem - mn);
}

void solve() {
    cin >> n >> tc >> timem;

    clients.assign(n, {0, 0, 0});
    for(int i = 0; i < n; i++) {
        int c, m, t;
        cin >> c >> m >> t;
        clients[i] = {c, m, t};
    }


    int ini = 1, mid, end = tc, ans = LLONG_MAX;
    while(ini <= end) {
        mid = (ini + end)/2;
        
        int mn = timem, deu = true;
        for(auto i : clients) {
            auto [cookies, muffins, time] = i;
            
            if(time <= cookies * mid) {
                deu = false;
                continue;
            }

            int x = (time - cookies * mid)/muffins;
            mn = min(x, mn);
        }

        int xd = f(mid), xd2 = f(mid + 1);
        ans = min({ans, xd, xd2});

        if(xd <= xd2) {
            end = mid - 1;
        } else ini = mid + 2;
    }
    cout << ans << endl;
    
}

int32_t main() {
    int ct = 1;
    cin >> ct;
    while(ct--)
        solve();
    return 0;
}