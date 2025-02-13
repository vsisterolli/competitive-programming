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
#define debug(x) cout << "DEBUG " << x << endl
#define debug2(x, y) cout << "DEBUG " << x << " " << y << endl
#define debug3(x, y, z) cout << "DEBUG " << x << " " << y << " " << z<< endl
#define debug4(x, y, z, o) cout << "DEBUG " << x << " " << y << " " << z<< " " << o << endl
#define all(x) (x).begin(), (x).end()
#define left esquerda
#define lb lower_bound
#define right direita
using namespace std;
void setIO(string s) {
ios_base::sync_with_stdio(0); cin.tie(0);
freopen((s+".in").c_str(),"r",stdin);
freopen((s+".out").c_str( ),"w",stdout);
}
typedef pair<int, int> pii;
typedef vector<vector<char>> mat;
typedef pair<int, string> pis;
const ll mod = 1e9 + 7, MAXN = 2e5 + 5;
typedef vector<int> vi;
typedef pair<int, pair<int, int>> piii;

bool cmp(piii a, piii b) {
    if(a.s.f != b.s.f)
        return a.s.f > b.s.f;
    return a.s.s > b.s.s;
}

int log2_floor(unsigned long long i) {
    return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1;
}

void solve() {
    int n;
    cin >> n;
    vector<piii> v(n);


    vector<pii> sfmn(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i].s.f >> v[i].s.s;
        v[i].f = i + 1;
    }
    sort(all(v), cmp);

    pii st[25][n + 1];
    for(int i = 0; i < n; i++)
        st[0][i] = {v[i].s.s, v[i].f};

    for (int i = 1; i < 25; i++)
        for (int j = 0; j + (1 << i) <= n; j++)
            st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
    

    sfmn[n - 1] = {v[n - 1].s.s, v[n-1].f};
    for(int i = n - 2; i >= 0; i--)
        sfmn[i] = min(sfmn[i + 1], {v[i].s.s, v[i].f});


    vector<int> pair(n + 1, -1);
    for(int i = 0; i < n; i++) {
        int ini = i + 1, mid, end = n - 1, best = n;
        while(ini <= end) {
            mid = (ini + end)/2;
            if(v[mid].s.f >= v[i].s.f)
                ini = mid + 1;
            else {
                best = min(best, mid);
                end = mid -1;
            }
        }

        if(best != n && sfmn[best].f < v[i].s.s) {
             pair[v[i].f] = sfmn[best].s;
             continue;
        }

        swap(v[i].s.f, v[i].s.s);
        ini = i + 1, mid, end = n - 1, best = n;
        while(ini <= end) {
            mid = (ini + end)/2;
            if(v[mid].s.f >= v[i].s.f)
                ini = mid + 1;
            else {
                best = min(best, mid);
                end = mid -1;
            }
        }

        if(best != n && sfmn[best].f < v[i].s.s) 
            pair[v[i].f] = sfmn[best].s;
         

        ini = 0, mid, end = i - 1, best = i;
        while(ini <= end) {
            mid = (ini + end)/2;
            if(v[mid].s.f >= v[i].s.f) 
                ini = mid + 1;
            else {
                best = min(best, mid);
                end = mid - 1;
            }
        }

        int lg = log2_floor(i - best + 1);
        pii minimum = min(st[lg][best], st[lg][i - (1 << lg) + 1]);

        if(best != i && minimum.f < v[i].s.s) 
            pair[v[i].f] = minimum.s;

        swap(v[i].s.f, v[i].s.s);
    }

    for(int i = 1; i <= n; i++)
        cout << pair[i] << " ";
    cout << endl;
}

int32_t main() {
    int ct = 1;
    cin >> ct;
    while(ct--)
        solve();
}