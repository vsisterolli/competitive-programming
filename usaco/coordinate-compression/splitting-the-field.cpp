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
#define debug(x) cout << "DEBUG " << x << endl
#define debug2(x, y) cout << "DEBUG " << x << " " << y << endl
#define debug3(x, y, z) cout << "DEBUG " << x << " " << y << " " << z<< endl
#define debug4(x, y, z, o) cout << "DEBUG " << x << " " << y << " " << z<< " " << o << endl
#define all(x) x.begin(), x.end()
#define left esquerda
#define lb lower_bound
#define right direita
#define int long long
using namespace std;
void setIO(string s) {
ios_base::sync_with_stdio(0); cin.tie(0);
freopen((s+".in").c_str(),"r",stdin);
freopen((s+".out").c_str( ),"w",stdout);
}
typedef pair<ll, ll> pii;
typedef vector<vector<char>> mat;
typedef pair<int, string> pis;
const ll mod = 1e9 + 7, MAXN = 2e5 + 5;
typedef vector<int> vi;
typedef pair<int, pair<int, int>> piii;

bool cmp(pii a, pii b) {
    return a.s < b.s;
}

void solve() {
    int n;
    cin >> n;

    vector<pii> v(n);
    int xx[4] = {LINF, -1, LINF, -1};
    for(pii &i : v) {
        cin >> i.f >> i.s;
        xx[0] = min(i.f, xx[0]);
        xx[1] = max(i.f, xx[1]);
        xx[2] = min(i.s, xx[2]);
        xx[3] = max(i.s, xx[3]);
    }
    sort(all(v));

    multiset<int> s;
    for(int i = 0; i < n; i++)
        s.insert(v[i].s);

    int l = LINF, r = 0;

    int ans = LINF;
    for(int i = 0; i < n; i++) {
        auto sr = s.end();
        sr--;

        auto sl = s.begin();

        int curans = (*sr - *sl) * (v[n - 1].f - v[i].f);
        if(i) 
            curans += (r - l) * (v[i - 1].f - v[0].f);       
        
        // debug2(i, curans);
        // debug4(*sr, *sl, v[n - 1].f, v[i].f);
        // if(i)
        //     debug4(r, l, v[i - 1].f, v[0].f);
        
        ans = min(ans, curans);
        l = min(v[i].s, l); 
        r = max(v[i].s, r);
        s.erase(s.find(v[i].s));

    }
    
    s.clear();
    sort(all(v), cmp);
    for(int i = 0; i < n; i++)
        s.insert(v[i].f);

    l = LINF, r = 0;
    for(int i = 0; i < n; i++) {
        
        auto sr = s.end();
        sr--;

        auto sl = s.begin();

        int curans = (*sr - *sl ) * (v[n - 1].s - v[i].s);
        if(i) 
            curans += (r - l ) * (v[i - 1].s - v[0].s );       
        
        ans = min(ans, curans);
        l = min(v[i].f, l); 
        r = max(v[i].f, r);
        s.erase(s.find(v[i].f));

    }

    cout << (xx[1] - xx[0]) * (xx[3] - xx[2]) - ans << endl;
}

int32_t main() {
    setIO("split
        ");
    int ct = 1;
    while(ct--)
        solve();
}