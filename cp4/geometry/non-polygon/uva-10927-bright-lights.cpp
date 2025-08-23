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

typedef struct Point {
    ll x, y, z;
    bool operator <(Point &a) {
        if(x * a.y != a.x * y)
            return x * a.y < a.x * y;
        if(x * x + y * y != a.x * a.x + a.y * a.y)
            return x * x + y * y < a.x * a.x + a.y * a.y;
        return z < a.z;
    }
} Point;

void solve(int n) {
    vector<Point> v;
    for(int i = 0; i < n; i++) {
        Point a;
        cin >> a.x >> a.y >> a.z;
        v.push_back(a);
    }

    vector<Point> nvi;
    sort(all(v));
    
    int mx = v[0].z;
    for(int i = 1; i < n; i++) {
        if(v[i].y * v[i - 1].x != v[i - 1].y * v[i].x) {
            mx = v[i].z;
            continue;
        }
        else if(v[i].z <= mx) 
            nvi.push_back(v[i]);
        

        mx = max(mx, v[i].z);
    }

    sort(all(nvi), [&](Point a, Point b) -> bool {
        if(a.x != b.x)
            return a.x < b.x;
        return a.y < b.y;
    });
    if(!nvi.size())
        cout << "All the lights are visible." << endl;
    else {
        cout << "Some lights are not visible:" << endl;

        for(int i = 0; i < nvi.size(); i++)
            cout << "x = " << nvi[i].x << ", y = " << nvi[i].y << (i + 1 == nvi.size() ? '.' : ';') << endl;
    }
}

int32_t main() {
    int n = 1, cont = 1;
    while(cin >> n) {
        if(!n)
            break;
        cout << "Data set " << cont++ << ":" << endl;
        solve(n);
    }
    return 0;
}