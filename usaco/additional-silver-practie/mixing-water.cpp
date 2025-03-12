
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

void solve() {
    int c, h, t;
    cin >> h >> c >> t;

    if(h <= t) 
        cout << 1 << endl;
    else if(c >= t) {
        cout << 2 << endl;
        return;
    }
    else if( (h + c) >= 2 * t) {
        cout << 2 << endl;
        return;
    }
    else {
        double bestAns = (double)abs((h + c)/2.0 - t);
        int bestTotal = 2;

        int x = (double)(t - h)/(h + c - 2.0 * t);
        double cur = (double)((h + c) * x + h)/(2.0 * x + 1.0);

        if(abs(cur - t) < bestAns) {
            bestAns = abs(cur - t);
            bestTotal = 2 * x + 1;
        }

        x++;
        cur = (double)((h + c) * x + h)/(2.0 * x + 1.0);

        if(abs(cur - t) < bestAns) {
            bestAns = abs(cur - t);
            bestTotal = 2 * x + 1;
        }

        x = 0;
        cur = (double)((h + c) * x + h)/(2.0 * x + 1.0);

        if(abs(cur - t) < bestAns) {
            bestAns = abs(cur - t);
            bestTotal = 2 * x + 1;
        }
        cout << bestTotal << endl;
    }
}

int32_t main() {
    int ct = 1;
    cin >> ct;
    while(ct--)
        solve();
    return 0;
}