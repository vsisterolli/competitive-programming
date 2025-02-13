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
#define debug3(x, y, z) cerr << "DEBUG " << x << " " << y << " " << z<< endl
#define debug4(x, y, z, o) cerr << "DEBUG " << x << " " << y << " " << z<< " " << o << endl
#define all(x) x.begin(), x.end()
#define left esquerda
#define int long long
#define lb lower_bound
#define right direita
using namespace std;
void setIO(string s) {
ios_base::sync_with_stdio(0); cin.tie(0);
freopen((s+".in").c_str(),"r",stdin);
freopen((s+".out").c_str( ),"w",stdout);
}
typedef pair<ll, ll> pii;
typedef vector<vector<char>> mat;
typedef pair<int, string> pis;
const ll mod = 1e9 + 7, MAXN = 2e5 + 5;
typedef vector<int> vi;
typedef pair<int, pair<int, int>> piii;

void solve() {
    int n, S, sum = 0;
    cin >> n >> S;

    vector<int> w(n), x(n), d(n);
    for(int i = 0; i < n; sum += w[i], i++)
        cin >> w[i] >> x[i] >> d[i];

    vector<int> order(n);
    iota(order.begin(), order.end(), 0);

    sort(all(order), [&](int a, int b) -> bool {
        return x[a] < x[b];
    });

    map<int, int> T, colision;
    int *l = &order[0], *r = &order[n-1];

    while(l <= r && d[*l] == -1) {
        T[2 * x[*l]] += w[*l];
        l++;
    }

    while(l <= r && d[*r] == 1) {
        T[2 * (S - x[*r])] += w[*r];
        r--;
    }

    vector<int> time_colision(n);
    while(l <= r) {
        int *aux = l + 1;

        while(aux <= r && d[*aux] != -1)
            aux++;

        if(aux > r) {

            while(l <= r) {
                T[time_colision[*l] + 2 * (S - x[*l])] += w[*l];
                l++;
            }
            break;

        }

        while(aux > l && aux <= r && d[*aux] == -1) {
            int ctime = time_colision[*aux];
            ctime += x[*aux] - x[*(aux - 1)];
            
            int c_position = x[*(aux - 1)] + (x[*aux] - x[*(aux - 1)])/2;
            debug(*l);
            debug4(ctime, c_position, *aux, *(aux - 1));


            colision[ctime]++;
            d[*aux] = 1;
            d[*(aux - 1)] = -1;
        
            x[*aux] = c_position;
            x[*(aux - 1)] = c_position;
            if( (x[*aux] - x[*(aux - 1)]) & 1 )
                x[*aux]++;
            
            time_colision[*aux] = time_colision[*(aux - 1)] = ctime;
            aux--;
        }

        T[ (2 * x[*l]) + time_colision[*l]] += w[*l];
        l++;

    }

    int total = 0;
    for(auto &i : T) {
        total += i.s;
        if(2 * total >= sum) {
            int ans = 0;
            for(auto j : colision)
                ans += (j.f <= i.f);
            cout << ans << endl;
            return;   
        }
    }


}

int32_t main() {
    // setIO("meetings");
    int ct = 1;    
    // cin >> ct;
    while(ct--)
        solve();
}