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

double heron(double a, double b, double c) {
    double s = (a + b + c) / 2.0;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

int32_t main() {
    int m;
    cin >> m;

    vector<double> v(m);
    for(double &i : v)
        cin >> i;
    
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {

        double a, b, c;
        cin >> a >> b >> c;

        if(c > b)
            swap(b, c);
        if(a < b)
            swap(a, b);
            
        double A = heron(a, b, c);
        double r = (a * b * c) / (4.0 * A);
        if(a * a >= b * b + c * c)
            r = a / 2.0;

        r = min({r, max({a, b, c})});
        vector<int> aux;
        for(int j = 0; j < m; j++)
            if(2 * r <= v[j])
                aux.push_back(j + 1);

        if(!aux.size())
            cout << "Peg " << char(i + 'A') << " will not fit into any holes" << endl;
        else {
            cout << "Peg " << char(i + 'A') << " will fit into hole(s):";
            for(int &j : aux)
                cout << " " << j;
            cout << endl;
        }
    }
}