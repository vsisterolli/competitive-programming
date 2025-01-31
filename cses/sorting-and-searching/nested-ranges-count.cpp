// HELPFUL HEADER ONLY
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
using namespace std;
void setIO(string s) {
ios_base::sync_with_stdio(0); cin.tie(0);
freopen((s+".in").c_str(),"r",stdin);
freopen((s+".out").c_str( ),"w",stdout);
}
typedef pair<ll, ll> pii;
typedef vector<vector<char>> mat;
typedef pair<int, string> pis;
const ll mod = 998244353, MAXN = 4e5 + 5;
typedef vector<int> vi;
typedef pair<pair<int, int>, int> piii;
// END HEADER

int BIT[MAXN];
int N;
void update(int x,int val) { while(x<=N)  { BIT[x]+=val;  x+=(x&-x);  } }
int query(int x) {  int res=0;  while(x>0)  {  res+=BIT[x];  x-=(x&-x);  } return res; } 

bool cmp(piii a, piii b) {
    if(a.f.f != b.f.f)
        return a.f.f > b.f.f;
    return a.f.s < b.f.s;
}

bool cmp2(piii a, piii b) {
    if(a.f.f != b.f.f)
        return a.f.f < b.f.f;
    return a.f.s > b.f.s;
}

int32_t main() {
//    FAST;   

    int n;
    cin >> n;

    N = 2 * n + 1;
    vector<piii> v(n);
    vector<int> sum(2 * n + 5);
    
    vector<int> cord;
    int aux = 0;
    for(piii &i : v) {
        cin >> i.f.f >> i.f.s;
        cord.pb(i.f.f);
        cord.pb(i.f.s);
        i.s = aux++;
    }
    sort(cord.begin(), cord.end());

    map<int, int> comp;
    for(int i = 0; i < cord.size(); i++)
        comp[cord[i]] = i + 1;

    for(piii &i : v) {
        i.f.f = comp[i.f.f];
        i.f.s = comp[i.f.s];
    }
    sort(v.begin(), v.end(), cmp);
    
    vector<pii> ans(n);
    for(piii &i : v) {
        ans[i.s].f = query(i.f.s);
        update(i.f.s, 1);
    }
    for(piii &i : v)
        update(i.f.s, -1);
    sort(v.begin(), v.end(), cmp2);
    
    for(piii &i : v) {
        ans[i.s].s = query(2 * n + 1) - query(i.f.s - 1);
        update(i.f.s, 1);
    }

    for(pii &i : ans)
        cout << i.f << " ";
    cout << endl;
    for(pii &i : ans)
        cout << i.s << " ";
    cout << endl;

}
