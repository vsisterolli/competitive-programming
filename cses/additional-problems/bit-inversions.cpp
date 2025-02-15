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

multiset<int> szs;
set<int> starts;
int sz[MAXN], n;

void join(int l, int r) {
    if(l == r)
        return;

    if(l > r)
        swap(l, r);

    szs.erase(szs.find(sz[l]));
    szs.erase(szs.find(sz[r]));
    starts.erase(r);

    sz[l] += sz[r];
    sz[r] = 0;

    szs.insert(sz[l]);
}

void cut(int x) {

    starts.insert(x);

    auto l = starts.find(x);
    l--;


    int nszl = (x - *l);
    int nszr = sz[*l] - nszl - 1;


    szs.erase(szs.find(sz[*l]));

    szs.insert(1);
    szs.insert(nszl);

    sz[*l] = nszl;
    sz[x] = 1;

    if(nszr) {
        szs.insert(nszr);
        starts.insert(x + 1);
        sz[x + 1] = nszr;
    }
    else if(x + 1 < n) 
        join(x, x + 1);
}

void solve() {
    string s;
    cin >> s;

    n = s.size();

    int cur = 1, cs = 0;
    for(int i = 1; i < n; i++) {
        if(s[i] == s[i - 1])
            cur++;
        else {
            sz[cs] = cur;
            szs.insert(cur);
            starts.insert(cs);
        
            cur = 1;
            cs = i;
        }
    }

    if(cur) {
        sz[cs] = cur;
        szs.insert(cur);
        starts.insert(cs); 
    }


    int q;
    cin >> q;

    while(q--) {

        
        int x;
        cin >> x;
        x--;
        
        if(n == 1) {
            cout << 1 << " ";
            continue;
        }

        if(sz[x]) {
            if(sz[x] == 1) {
                if(!x)
                    join(0, 1);
                else if(x == n - 1) {
                    auto aux = starts.lower_bound(x);
                    aux--;
                    
                    join(*aux, x);
                }
                else {
                    auto aux = starts.lower_bound(x);
                    aux--;
                    join(*aux, x);
                    join(*aux, x+1);
                }

            }

            else {
                szs.erase(szs.find(sz[x]));
                szs.insert(1);
                szs.insert(sz[x] - 1);
                sz[x + 1] = sz[x] - 1;
                sz[x] = 1;

                starts.insert(x + 1);
                
                if(x) {
                    
                    auto aux = starts.lower_bound(x);
                    aux--;
                    join(*aux, x);
                
                }

            }
        }
        else cut(x);

        auto ans = szs.end();
        ans--;

        cout << *ans << " ";
    }
    cout << endl;
}

int32_t main() {
    FAST;
    int ct = 1;
    // cin >> ct;
    while(ct--)
        solve();
    return 0;
}