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
#define sz(x) (int)(x).size()
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
    int n, m;
    cin >> n >> m;

    vi def, atk;
    for(int i = 0; i < n; i++) {
        string t;
        int s;
        cin >> t >> s;
        if(t == "ATK")
            atk.pb(s);
        else def.pb(s);
    }
    sort(all(atk));
    sort(all(def));

    multiset<int> cards;
    for(int i = 0; i < m; i++) {
        int x;
        cin >> x;
        cards.insert(x);
    }

    vector<int> kek;
    int pa = 0;
    for(int i = 0; i < atk.size(); i++) {
        auto aux = cards.end();
        if(aux == cards.begin()) {
            cout << pa << endl;
            return;
        }
        aux--;
        
        if(*aux < atk[i])
            break;
        
        pa += (*aux - atk[i]);
        kek.push_back(*aux);
        cards.erase(aux);
    }

    for(int &i : kek)
        cards.insert(i);

    int ans = 0;
    for(int i = sz(atk) - 1; i >= 0; i--) {
        auto aux = cards.upper_bound(atk[i]);
        if(aux == cards.end()) {
            cout << max(pa, ans) << endl;
            return;
        }
        ans += (*aux - atk[i]);
        cards.erase(aux);
    }

    for(int i = 0; i < def.size(); i++) {
        auto aux = cards.upper_bound(def[i]);
        if(aux == cards.end()) {
            cout << max(pa, ans) << endl;
            return;
        }
        cards.erase(aux);
    }

    while(!cards.empty()) {
        ans += *cards.begin();
        cards.erase(cards.begin());
    }
    cout << max(pa, ans) << endl;

}

int32_t main() {
    int ct = 1;
    // cin >> ct;
    while(ct--)
        solve();
    return 0;
}