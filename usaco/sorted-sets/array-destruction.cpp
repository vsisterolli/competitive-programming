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
    n *= 2;

    vector<int> v(n);
    multiset<int> s;

    int max = 0;
    for(int i = 0; i < n; i++) {
        cin >> v[i];
        if(v[i] > v[max])
            max = i;
    }


    for(int i = 0; i < n; i++) {
            
        if(i == max)
            continue;

        s.clear();
        for(int j = 0; j < n; j++)
            s.insert(v[j]); 

        int xi = v[i] + v[max];

        vector<pii> ans;

        int x = xi;
        bool flag = true;
        while(!s.empty()) {
            auto r = s.end();
            r--;
            
            auto l = s.find(x - *r);
            int kek1 = *r, kek2 = *l;
            // debug4(xi, x, kek1, kek2);
            // debug(s.size());
            if(l == s.end() || l == r) {
                flag = false;
                break;
            }

            ans.pb({*l, *r});
            x = *r;

            s.erase(s.find(kek1));
            s.erase(s.find(kek2));
        }
        
        if(flag) {
            cout << "YES" << endl << xi << endl;
            for(pii &j: ans) 
                cout << j.f << " " << j.s << endl;
            return;
        }

    }

    cout << "NO" << endl;
    

}

int32_t main() {
    int ct = 1;
    cin >> ct;
    while(ct--)
        solve();
    return 0;
}