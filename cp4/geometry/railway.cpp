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
typedef pair<double, double> pii;
typedef vector<vector<char>> mat;
typedef pair<int, string> pis;
const ll mod = 1e9 + 7, MAXN = 2e5 + 5;
typedef vector<int> vi;
typedef pair<int, pair<int, int>> piii;

const double EPS = 1e-9;

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

double getSegSize(point a, point b) {
    point aux = a - b;
    return hypot(aux.x, aux.y);
}

double dot(point A, point B) {
    return A.x * B.x + A.y * B.y;
}

double cross(point A, point B) {
    return A.x * B.y - A.y * B.x;
}

bool collinear(point A, point B, point C) {
    return (abs(cross(A - C, B - C)) < EPS);
}

double distanceToLine(point A, point B, point pivot) {
    double a = getSegSize(pivot, A);
    double b = getSegSize(pivot, B);
    double c = getSegSize(A, B);

    if(collinear(A, B, pivot)) {
        if(pivot.x >= min(A.x, B.x) && pivot.x <= max(A.x, B.x) && pivot.y >= min(A.y, B.y) && pivot.y <= max(A.y, B.y))
            return 0.0;
        
        else return min(getSegSize(pivot, A), getSegSize(pivot, B));
    }

    double s = (a + b + c) / 2.0;
    return sqrt(s * (s - a) * (s - b) * (s - c)) / c;
}

point getClosestPoint(const point &A, const point &B, const point &P) {
    point AB = B - A;
    point AP = P - A;
    double denom = dot(AB, AB);
    if (denom < EPS) return A;               // degenerate segment
    double t = dot(AP, AB) / denom;
    if (t < 0.0)      return A;              // before A
    if (t > 1.0)      return B;              // after B
    return A + (AB * t);                     // between A and B
}


int32_t main() {
    point pivot;
    while(cin >> pivot.x) {
        cin >> pivot.y;
        double dist = LINF;
        point ans = {0, 0};
        
        int n;
        cin >> n;
        n++;

        vector<point> points(n);
        for(point &i : points)
            cin >> i.x >> i.y;

        for(int i = 1; i < n; i++) {
            point pointB = points[i], pointA = points[i - 1];

            if(distanceToLine(pointA, pointB, pivot) < dist) {
                dist = distanceToLine(pointA, pointB, pivot);
                ans = getClosestPoint(pointA, pointB, pivot);
            }
        }
        cout << fixed << setprecision(4) << ans.x << endl << ans.y << endl;

    }
}