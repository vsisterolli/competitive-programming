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
    string s, t;
    cin >> s >> t;
    swap(s, t);

    vector<pii> si, ti;
    
    int i = 0;
    while(i < s.size()) {
        int first = i;
        int sz = 0;
        
        while(i < s.size() && s[i] == s[first]) {
            i++;
            sz++;
        }

        si.push_back({sz, s[first]});
    }
    
    i = 0;
    while(i < t.size()) {
        int first = i;
        int sz = 0;
        
        while(i < t.size() && t[i] == t[first]) {
            i++;
            sz++;
        }

        ti.push_back({sz, t[first]});
    }

    int ptr = 0, othersz = 0, others = 0, ans = 0;
    
    int sum = 0;
    for(pii &cur : si) {

        bool flag = false;
        while(sum < cur.f) {
            if(!flag) {
                sum += othersz;
                othersz = 0;
                flag = true;
            }

            if(ptr == ti.size())
                break;
            
            if(cur.s == ti[ptr].s) {
                sum += ti[ptr].f;
                ans += others;
                others = 0;
            }
            else {
                othersz += ti[ptr].f;
                others++;
            }
            ptr++;
        }

        if(sum != cur.f) {
            cout << -1 << endl;
            return;
        }   
        sum = 0;
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