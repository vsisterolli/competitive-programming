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


const double EPS = 1e-9;
struct lineSegment {
    double a, b, c, mnx, mxx, mny, mxy;
    lineSegment() {};
    lineSegment(point const &p1, point const &p2) {
        mnx = min(p1.x, p2.x);
        mxx = max(p1.x, p2.x);
        mny = min(p1.y, p2.y);
        mxy = max(p1.y, p2.y);
        if(abs(p1.x - p2.x) < EPS)
        a = 1.0, b = 0, c = -p1.x;
        else {
            a = -(p1.y - p2.y)/(p1.x - p2.x), b = 1.0;
            c = -(a * p1.x + p1.y);
        }
    };
    
    bool inside(point p) {
        return (p.x + EPS >= mnx && p.x - EPS <= mxx && p.y + EPS >= mny && p.y - EPS <= mxy);
    }
};


bool areParallel(lineSegment l1, lineSegment l2) { // check a & b
    return (fabs(l1.a-l2.a) < EPS) && (fabs(l1.b-l2.b) < EPS);
}
bool intersect(lineSegment l1, lineSegment l2) {
    if (areParallel(l1, l2)) {
        
        if(abs(l1.c - l2.c) < EPS) {
            if(abs(l1.b) < EPS) 
                return (l1.mxy > l2.mny || l2.mxy > l1.mxy);
            else
                return (l1.mxx > l2.mnx || l2.mxx > l1.mxx);
        }
        return false;
    }

    point p;
    p.x = (l2.b*l1.c - l1.b*l2.c) / (l2.a*l1.b - l1.a*l2.b);
    if (fabs(l1.b) > EPS) p.y = -(l1.a*p.x + l1.c);
    else p.y = -(l2.a*p.x + l2.c);

    return (l1.inside(p) && l2.inside(p));
}

void solve(int n) {
    vector<lineSegment> v(n);
    for(int i = 0; i < n; i++) {
        point a, b;
        cin >> a.x >> a.y >> b.x >> b.y;
        v[i] = lineSegment(a, b);
    }

    vector<bool> alone(n, 1);
    int ans = 0;
    for(int i = 0; i < n; i++) 
        for(int j = i + 1; j < n; j++) {
            if(intersect(v[i], v[j])) {
                alone[j] = 0;
                alone[i] = 0;
                ans++;
            }
        }

    for(bool i : alone)
        ans += i * 2;
    cout << ans << endl;
    
}

int32_t main() {
    int n = 1;
    while(cin >> n) {
        if(!n)
            break;
        solve(n);
    }
    return 0;
}