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
    double x, y;
    point() {};
    point(double x_, double y_) : x(x_), y(y_) {};

    point operator -(point a) {
        return point(x - a.x, y - a.y);
    }
    bool operator == (point a) const {
        return ((a.x == x) && (a.y == y));
    }
    bool operator < (point a) {
        if(a.x != x)
            return x < a.x;
        return y < a.y;
    }
    double length() {
        return sqrt(x * x + y * y); 
    }
} point;

double cross(point v1, point v2) {
    return v1.x * v2.y - v1.y  * v2.x;
}

const double EPS = 1e-9;

// compute the intersection point between line segment p-q and line A-B
point lineIntersectSeg(point p, point q, point A, point B) {
    double a = B.y-A.y, b = A.x-B.x, c = B.x*A.y - A.x*B.y;
    double u = fabs(a*p.x + b*p.y + c);
    double v = fabs(a*q.x + b*q.y + c);
    return point((p.x*v + q.x*u) / (u+v), (p.y*v + q.y*u) / (u+v));
}

// returns the left side of a polygon cutten by A->B
// if wants right side, just swap A, B
vector<point> cutPolygon(point A, point B, vector<point> &Q) {
    vector<point> P;
    for (int i = 0; i < (int)Q.size(); ++i) {
        double left1 = cross(B - A, Q[i] - A), left2 = 0;
        if (i != (int)Q.size()-1) 
            left2 = cross(B - A, Q[i+1] - A);

        if (left1 + EPS > 0) 
            P.push_back(Q[i]);

        // 1 point to left and 1 to right (diff signs)
        if (left1*left2 + EPS < 0) 
            P.push_back(lineIntersectSeg(Q[i], Q[i+1], A, B));
    }
    if (!P.empty() && !(P.back() == P.front()))
        P.push_back(P.front()); 

    return P;
}

double getArea(vector<point> p) {
    int n = p.size();
    double ans = 0.0;
    for(int i = 0; i + 1 < n; i++)  
        ans += cross(p[i], p[i + 1]);
    
    return ans / 2.0;
}

void solve() {
    point f;
    int n, w, h;
    int ct = 1;
    while(cin >> n >> w >> h >> f.x >> f.y) {
        vector<point> polygon = {point(0, 0), point(w, 0), point(w, h), point(0, h), point(0, 0)};
        for(int i = 0; i < n; i++) {
            point a, b;
            cin >> a.x >> a.y >> b.x >> b.y;
            if(cross(b - a, f - a) + EPS < 0)
                swap(a, b);
            polygon = cutPolygon(a, b, polygon);
        }
        cout << "Case #" << fixed << setprecision(3) << ct << ": " << getArea(polygon) << endl;
        ct++;
    }
}

int32_t main() {
    // int ct = 1;
    // // cin >> ct;
    // while(ct--)
    solve();
    return 0;
}