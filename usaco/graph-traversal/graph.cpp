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
#define int long long
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
const ll mod = 1e9 + 7, MAXN = 1e5 + 5;
typedef vector<int> vi;
typedef pair<int, pair<int, int>> piii;

vector<pii> g[MAXN];
vi sign(MAXN), used(MAXN);
vi comp;
vector<double> ct(MAXN);

bool definedX = false;
double Xv = 0;

void dfs(int u) {
    used[u] = 1;
    comp.push_back(u);

    for(pii &i : g[u]) {
        int sign_ = -sign[u];
        double ct_ = i.s - ct[u];

        if(!used[i.f]) {
            sign[i.f] = sign_;
            ct[i.f] = ct_;
            dfs(i.f);
        }

        else {

            if(sign[i.f] == sign_ && abs(ct[i.f] - ct_) > 1e-6) {
                cout << "NO" << endl;
                exit(0);
            }

            if(sign[i.f] != sign_) {
                
                // sign[i.f] * x + ct[i.f] = -sign[i.f] * x + _ct
                // 2 * sign[i.f] * x = _ct - ct[i.f]

                double x = (double)(ct_ - ct[i.f])/(2 * sign[i.f]);
                Xv = x;
                definedX = true;

            }

        }
    }
}

void dfs2(int u) {
    used[u] = 1;
    for(pii &i : g[u]) {

        if(!used[i.f] && sign[i.f] != 3) {
            ct[i.f] = i.s - ct[u];
            dfs2(i.f);
        }
        else {
            if(abs(ct[i.f] - (i.s - ct[u])) > 1e-6) {
                cout << "NO" << endl;
                exit(0);
            }

            if(!used[i.f])
                dfs2(i.f);
        }

    }
}

double f(double mid) {
    double tot = 0;
    for(int &u : comp)
        tot += (double) abs(mid * sign[u] + ct[u]);
    return tot;
}

double ternary_search(double L = -1e9, double R = 1e9) {
    for (int i = 0; i < 1000; i++) { 
        double m1 = L + (R - L) / 3.0;
        double m2 = R - (R - L) / 3.0;
        double f1 = f(m1), f2 = f(m2);
        if (f1 > f2)
            L = m1;
        else
            R = m2;
    }
    return (L + R) / 2.0;
}


int32_t main() {
    FAST;
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;

        if(a == b) {
            if(!used[a]) ct[a] = (double) c/2.0;
            else if(ct[a] != (double) c/ 2.0) {
                cout << "NO" << endl;
                return 0;
            }
            sign[a] = 3;
        }
        else {
            g[a].pb({b, c});
            g[b].pb({a, c});
        }
    }

    for(int i = 0; i < n; i++) {
        if(!used[i] && sign[i] == 3) 
            dfs2(i);
        
    }

    for(int i = 0; i < n; i++) {

        if(used[i])
            continue;

        definedX = false;
        sign[i] = 1;
        comp.clear();
        dfs(i);

        if(definedX) 
            for(int &u : comp) 
                ct[u] = (double) Xv * sign[u] + ct[u];

        else {
            double best_x = ternary_search();
            for(int &u : comp)
                ct[u] = (double) best_x * sign[u] + ct[u];
        }
        
    }

    for(int i = 0; i < n; i++)
        for(pii &j : g[i]) {
            if ( abs((ct[j.f] + ct[i]) - j.s) > 0.0001 ) {
                cout << "NO" << endl;
                return 0;
            } 
        }

    cout << "YES" << endl;
    for(int i = 0; i < n; i++)
        cout << fixed << setprecision(6) << ct[i] << " ";
    cout << endl;
}