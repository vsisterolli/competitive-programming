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
    point(double x_, double y_) : x(x_), y(y_) {}

    point operator-(const point &a) const {
        return point(x - a.x, y - a.y);
    }
    point operator*(const double &a) const {
        return point(x * a, y * a);
    }
    point operator+(const point &a) const {
        return point(x + a.x, y + a.y);
    }
} point;

double cross(point A, point B) {
    return A.x * B.y - A.y * B.x;
}

point circleOrigin(point p1, point p2, point p3) {
    // assert points are not collinear
    assert(cross(p3 - p1, p2 - p1) > 1e-12);
        
    double a, b, c, d, e, f;
    double dx, dy, dd;
    a = p1.x - p2.x, b = p1.y - p2.y;
    c = a*((p1.x+p2.x)/2) + b*((p1.y+p2.y)/2);
    d = p2.x - p3.x, e = p2.y - p3.y;
    f = d*((p2.x+p3.x)/2) + e*((p2.y+p3.y)/2);
    point o;
    dd = a*e - b*d;
    dx = c*e - b*f;
    dy = a*f - d*c;
    o.x = dx/dd, o.y = dy/dd;
    return o;
}

point rotateCounterClockwise(double ang, point p) {
    double radAng = (ang/180.0 * acos(-1));
    return point(p.x * cos(radAng) - p.y * sin(radAng), p.x * sin(radAng) + p.y * cos(radAng));
}

void solve(int ct) {
    int n;
    cin >> n;
    if(n == 0)
        exit(0);

    point p[3];
    for(int i = 0; i < 3; i++)
        cin >> p[i].x >> p[i].y;
    
    point o = circleOrigin(p[0], p[1], p[2]);
    point vector = p[0] - o;

    cout << fixed << setprecision(3);
    cerr << fixed << setprecision(3);

    double mxx = -1e9, mnx = 1e9, mxy = -1e9, mny = 1e9;
    for(int i = 0; i < n; i++) {
        double ang = (360.0 / (double)n) * i;
        
        point rotatedVector = rotateCounterClockwise(ang, vector);
        point aux = o + rotatedVector;

        // debug2(aux.x, aux.y);
        mxx = max(mxx, aux.x), mnx = min(mnx, aux.x);
        mxy = max(mxy, aux.y), mny = min(mny, aux.y);
    }
    // debug4(mxx, mnx, mxy, mny);
    cout <<"Polygon " << ct << ": " << (mxx - mnx) * (mxy - mny) << endl;
}

int32_t main() {
    int ct = 0;
    // cin >> ct;
    while(++ct)
        solve(ct);
    return 0;
}