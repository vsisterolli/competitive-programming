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

double dot(point A, point B) {
    return A.x * B.x + A.y * B.y;
}

double getSegSize(point a, point b) {
    point aux = a - b;
    return hypot(aux.x, aux.y);
}

double getDistance(const point &A, const point &B, const point &P) {
    point AB = B - A;
    point AP = P - A;
    double denom = dot(AB, AB);
    point best;
    if (denom < EPS) best = A;
    else {               
        double t = dot(AP, AB) / denom;
        if (t < 0.0)      best = A; 
        else if (t > 1.0)      best = B;   
        else best = A + (AB * t);                    
    }           
    
    return hypot(P.x - best.x, P.y - best.y);
}

void solve(int n) {
    point pivot;
    cin >> pivot.x >> pivot.y;
    vector<point> v(n);
    for(point &i : v)
        cin >> i.x >> i.y;

    double ans = getDistance(v[n -1], v[0], pivot);
    for(int i = 1; i < n; i++) 
        ans = min(ans, getDistance(v[i - 1], v[i], pivot));
    cout << fixed << setprecision(3) << ans << endl;
}

int32_t main() {
    string n;
    while(cin >> n) {
        if(n == "*")
            break;
        solve(stoi(n));
    }
    return 0;
}