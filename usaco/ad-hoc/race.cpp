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
#define int long long
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

    setIO("race");
    int k, q;
    cin >> k >> q;

    int gans = -1;
    while(q--) {
        int l;
        cin >> l;

        if(l >= gans && gans != -1) {
            cout << gans << endl;
            continue;
        }

        int backup = k;

        ll x = k + ((l - 1) * l)/2;

        ll aux = sqrt(x);
        k -= (1 + aux) * aux/2;
        
        if(gans == -1 && k < 0) {
            while(k < 0) {
                gans = aux;
                aux--;
                k = backup;
                k -= (1 + aux) * aux/2;
            }
            cout << gans << endl;
            continue;
        }

        k -= (aux + l - 1) * (aux - l)/2;

        cout << aux + aux - l + ((k + aux - 1)/aux) << endl;

        k = backup;
    }
}

