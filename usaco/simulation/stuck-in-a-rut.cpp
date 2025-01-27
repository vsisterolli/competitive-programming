// HELPFUL HEADER ONLY
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
#define all(x) x.begin(), x.end()
#define left esquerda
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
// END HEADER


int32_t main() {
    int n;
    cin >> n;

    char d[n];
    ll x[n], y[n];

    for(int i = 0; i < n; i++)
        cin >> d[i] >> x[i] >> y[i];


    vector<ll> ans(n, LINF);
    for(int k = 0; k < n; k++) {
        int next = -1;
        ll small = LINF;

        for(int i = 0; i < n; i++) {
            ll xd = LINF;
            if(ans[i] != LINF)
                continue;
                
            for(int j = 0; j < n; j++) {
                if(d[i] == 'N' && y[j] <= y[i])
                    continue;
                if(d[i] == 'E' && x[j] <= x[i])
                    continue;

                if(d[i] == 'N') {
                    if(d[j] == 'N' && y[j] > y[i] && x[i] == x[j])
                        xd = min(xd, y[j] - y[i]);
                    else if(d[j] == 'N' && x[i] != x[j])
                        continue;
                    
                    else if(d[j] == 'E' && x[j] > x[i])
                        continue;
                    else if(d[j] == 'E') {
                        ll steps = y[j] - y[i];
                        if(x[j] + min(ans[j], steps) > x[i])
                            xd = min(xd, steps);
                    }
                } 
                else {
                    if(d[j] ==  'E' && y[i] != y[j])
                        continue;
                    else if(d[j] == 'E' && x[j] > x[i])
                        xd = min(xd, x[j] - x[i]);
                
                    else if(d[j] == 'N' && y[j] > y[i])
                        continue;
                    else if(d[j] == 'N') {
                        ll steps = x[j] - x[i];
                        if(y[j] + min(ans[j], steps) > y[i])
                           xd = min(xd, steps);                    }
                }
            }
            if(xd < small) {
                next = i;
                small = xd;
            }
        }

        if(next == -1)
            break;
        ans[next] = small;
    }

    for(ll &i : ans){
        if(i == LINF)
            cout << "Infinity" << endl;
        else cout << i << endl;
    }
}

