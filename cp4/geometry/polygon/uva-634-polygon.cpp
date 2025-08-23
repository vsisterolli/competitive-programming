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
    int x, y;
    point() {};
    point(int x_, int y_) : x(x_), y(y_) {};

    point operator -(point a) {
        return point(x - a.x, y - a.y);
    }
    
    double length() {
        return sqrt(x * x + y * y); 
    }
} point;

int cross(point v1, point v2) {
    return v1.x * v2.y - v1.y  * v2.x;
}

int dot(point v1, point v2) {
    return v1.x * v2.x + v1.y * v2.y;
}


bool ccw(point p, point q, point r) {
    return cross(q - p, r - p) > 0 ;
}

double angle(point a, point o, point b) {
    point oa = a - o, ob = b - o;
    return acos(dot(oa, ob) / (oa.length() * ob.length())  );
}

// 1 if inside, 0 if in edge/vertex, -1 if outside
int isInside(vector<point> &polygon, point p) {

    int n = polygon.size();
    if(n <= 3)
        return -1;

    double ans = 0;
    for(int i = 0; i + 1 < n; i++) {
        if (abs(dist(polygon[i], p) + dist(p, polygon[i+1]) -
                dist(polygon[i], polygon[i+1])) < EPS)
            return 0;
            
        if(ccw(p, polygon[i], polygon[i + 1]))
            ans += angle(polygon[i], p, polygon[i + 1]);
        else ans -= angle(polygon[i], p, polygon[i + 1]);
    }

    return (abs(ans) > acos(-1) ? 1 : -1);
}

void solve() {
    int n;
    
    while(cin >> n) {

        if(!n)
            return;

        vector<point> v(n);
        for(point &i : v)
            cin >> i.x >> i.y;
        v.push_back(v[0]);
        
        point p;
        cin >> p.x >> p.y;
        cout << (isInside(v, p) ? "T" : "F") << endl;

    }

}

int32_t main() {
    solve();
    return 0;
}