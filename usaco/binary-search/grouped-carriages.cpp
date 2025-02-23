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

    vector<int> v(n), mv(n);
    for(int &i : v)
        cin >> i;
    for(int &i : mv)
        cin >> i;
    
    vector<tuple<int, int, int>> people;
    for(int i = 0; i < n; i++)
        if(v[i])
            people.push_back({max(0ll, i - mv[i]), min(n - 1, i + mv[i]), v[i]});

    sort(all(people));

    int ini = 0, mid, end = 1e9 + 1, ans = 1e9;
    while(ini <= end) {
        mid = (ini + end)/2;

        int ptr = 0;
        priority_queue<pii, vector<pii>, greater<pii>> fila;

        bool deu = true;
        for(int i = 0; i <= n; i++) {
                
            if(!fila.empty() && fila.top().first < i) {
                deu = false;
                break;
            }
            
            if(i == n)
                break;

                
            while(1 && people.size()) {
                auto [l, r, am] = people[ptr];
                if(ptr < people.size() && l <= i) {
                    fila.push({r, am});
                    ptr++;
                }
                else break;
            }

            
            int k = mid;
            while(k && !fila.empty()) {
                pii cur = fila.top();
                fila.pop();

                int rmv = min(cur.s, k);
                k -= rmv;
                cur.s -= rmv;

                if(cur.s)
                    fila.push({cur.f, cur.s});
            }
        }

        if(deu) {
            ans = min(ans, mid);
            end = mid - 1;
        } else ini = mid + 1;
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