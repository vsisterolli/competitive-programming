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

void solve() {
    int L, W, T;
    cin >> L >> W >> T;
    if(!T) {
        cout << 1.000 << endl;
        return;
    }
    

    double radT = ((double)T/360.0) * 2.0 * M_PI;

    double sum = 0;
    point cur = {0, 0};

    double aux = tan(radT);    
    double x = W/aux;

    
    int tot = (int)floor((double)L/x);
    sum += hypot(x, W) * tot;
    
    cur = {(double)tot * x, (tot & 1 ? W : 0)};
    
    if(abs(W - cur.y) < EPS) {
        double newH = W - ((L - cur.x) * aux);    
        sum += hypot(L - cur.x, newH - cur.y);
        cur = {L, newH};
    }
    else {
        double newH = (L - cur.x) * aux;
        sum += hypot(L - cur.x, newH - cur.y);
        cur = {L, newH};
    }
    
    double B = hypot(cur.x, cur.y);
    cout << fixed << setprecision(3) << sum/B << endl;

}

int32_t main() {
    int ct = 1;
    cin >> ct;
    while(ct--)
        solve();
    return 0;
}