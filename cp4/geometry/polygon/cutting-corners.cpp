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

int dot(point a, point b) {
    return a.x * b.x + a.y * b.y;
}

double angle(point a, point o, point b) {
    point oa = a - o, ob = b - o;
    return acos((double)dot(oa, ob) / (oa.length() * ob.length())  );
}

vector<point> skipPos(vector<point> &v, int p) {
    vector<point> ans;
    for(int i = 0; i < v.size(); i++)
        if(i != p)
            ans.push_back(v[i]);
    return ans;
}

pair<double, int> acutestAngle(vector<point> &v) {
    int n = v.size();
    
    pair<double, int> ans = {1e9, 0};
    for(int i = 0; i < n; i++){

        double curAng;
        if(i == 0) 
            curAng = angle(v[n - 1], v[0], v[1]);
        else if(i == n - 1)
            curAng = angle(v[n - 2], v[n - 1], v[0]);
        else curAng = angle(v[i - 1], v[i], v[i + 1]);

        if(curAng < ans.first) 
            ans = {curAng, i};
    
    }
    return ans;
}

void solve() {
    int n;
    while(cin >> n) {
        if(!n)
            return;

        vector<point> v(n);
        for(point &i : v)
            cin >> i.x >> i.y;
    
        while(v.size() > 3) {
            pair<double, int> best = acutestAngle(v);
            vector<point> nv = skipPos(v, best.s);
            if(acutestAngle(nv).f + 1e-9 < best.f)
                break;
            else v = nv;
        }

        cout << v.size();
        for(point &i : v)
            cout << " " << i.x << " " << i.y;
        cout << endl;
    }    
}

int32_t main() {
    int ct = 1;
    // cin >> ct;
    while(ct--)
        solve();
    return 0;
}