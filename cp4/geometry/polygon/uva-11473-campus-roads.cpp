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

typedef struct point {
    long double x, y;
    point() {};
    point(long double x_, long double y_) : x(x_), y(y_) {};

    point operator -(point a) {
        return point(x - a.x, y - a.y);
    }
     
    point operator +(point a) {
        return point(x + a.x, y + a.y);
    }

    point operator *(long double a) {
        return point(x * a, y * a);
    }
    
    long double length() {
        return sqrt(x * x + y * y); 
    }
} point;

long double dist(point A, point B) {
    return sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y));
}

const long double EPS = 1e-9;

void solve() {
    long double walk = 0.0;
    vector<point> ans;
    
    int n, k;
    cin >> n >> k;

    vector<point> road(n);
    for(point &i : road)
        cin >> i.x >> i.y;

    for(int i = 0; i + 1 < n; i++) 
        walk += dist(road[i + 1], road[i]);
    
    walk = (long double) walk / (long double) (k - 1);
    ans.push_back(road[0]);

    long double need = walk;
    point last = road[0];
    int gt = 1;

    while(gt < n) {
        long double vSize = (road[gt] - last).length();
        if(vSize < need) {
            last = road[gt];
            gt++;
            need -= vSize;
            continue;
        }
        else {
            last = last + ((road[gt] - last) * (need/vSize));
            ans.push_back(last);
            need = walk;
        }
    }
    
    ans.back() = road[n - 1];
    for(point &i : ans)
        cout << fixed << setprecision(2) << i.x << " " << i.y << endl;
    cout << endl;

}

int32_t main() {
    int ct = 1;
    cin >> ct;
    int cnt = 1;
    while(ct--) {
        cout << "Road #" << cnt << ":" << endl; 
        cnt++;
        solve();
    }
    return 0;
}