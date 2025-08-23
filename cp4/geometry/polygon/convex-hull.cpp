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

int cross(point a, point b)  {
    return a.x * b.y - a.y * b.x;
}

bool ccw(point p, point q, point r) {
    return cross(q - p, r - p) > 0 ;
}


vector<point> CH_Andrew(vector<point> &Pts) {
    int n = Pts.size(), k = 0;
    vector<point> H(2*n);
    sort(Pts.begin(), Pts.end()); 
    for (int i = 0; i < n; ++i) { 
        if(i && Pts[i].x == Pts[i - 1].x && Pts[i].y == Pts[i - 1].y)
            continue;
        while ((k >= 2) && !ccw(H[k-2], H[k-1], Pts[i]))
            k--;
        H[k++] = Pts[i];
    }
    for (int i = n-2, t = k+1; i >= 0; --i) { 
        if(i && Pts[i].x == Pts[i - 1].x && Pts[i].y == Pts[i - 1].y)
            continue;
        while ((k >= t) && !ccw(H[k-2], H[k-1], Pts[i])) 
            k--;
        H[k++] = Pts[i];
    }
    H.resize(k);
    return H;
}

void solve() {
    int n;
    while(cin >> n) {
        if(!n)
            return;

        vector<point> v(n);
        for(point &i : v)
            cin >> i.x >> i.y;

        vector<point> ch = CH_Andrew(v);
        cout << (int)ch.size() - 1 << endl;
        for(int i = 0; i + 1 < ch.size(); i++)
            if(ch[i].x != -1e9)
                cout << ch[i].x << " " << ch[i].y << endl;
    }
}

int32_t main() {
    solve();
    return 0;
}