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


int cross(point A, point B) {
    return A.x * B.y - A.y * B.x;
}

bool collinear(point A, point B, point C) {
    return !(cross(A - C, B - C));
}


double getSegSize(point a, point b) {
    point aux = a - b;
    return hypot(aux.x, aux.y);
}

const double EPS = 1e-9;

double distanceToLine(point A, point B, point pivot) {
    if(collinear(A, B, pivot)) 
        return 0.0;
    double a = getSegSize(pivot, A);
    double b = getSegSize(pivot, B);
    double c = getSegSize(A, B);

    double s = (a + b + c) / 2.0;
    return (s * (s - a) * (s - b) * (s - c)) / (c * c);
}

void solve() {
    point A, B;
    cin >> A.x >> A.y >> B.x >> B.y;
    
    int n;
    cin >> n;
    
    double best = LINF;
    vector<string> name(n);
    vector<double> dist(n);

    for(int i = 0; i < n; i++) {
        cin >> name[i];
        point pivot;
        cin >> pivot.x >> pivot.y;
        dist[i] = distanceToLine(A, B, pivot);
        best = min(best, dist[i]);
    }

    vector<string> ans;
    for(int i = 0; i < n; i++) {
        if(abs(best - dist[i]) < EPS)
            ans.push_back(name[i]);
    }

    for(auto &i : ans)
        cout << i << " ";
    cout << endl;

}

int32_t main() {
    int ct = 1;
    cin >> ct;
    while(ct--)
        solve();
    return 0;
}