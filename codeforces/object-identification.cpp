#pragma GCC optimize("Ofast")
 
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
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
using namespace __gnu_pbds;
 
void setIO(string s) {
ios_base::sync_with_stdio(0); cin.tie(0);
freopen((s+".in").c_str(),"r",stdin);
freopen((s+".out").c_str( ),"w",stdout);
}
typedef pair<int, ll> pii;
typedef vector<vector<char>> mat;
typedef pair<int, string> pis;
const ll mod = 1e9 + 7, MAXN = 2e5 + 5;
typedef vector<int> vi;
typedef pair<int, pair<int, int>> piii;
const int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash {
    int operator()(int x) const { return x ^ RANDOM; }
};

 
void solve() {
    int n;
    cin >> n;
    
    vector<int> v(n);
    
    int x1 = 0, xn = 0;
    for(int i = 0; i < n; i++) {
        cin >> v[i];
        if(v[i] == 1)
            x1 = i + 1;
        if(v[i] == n)
            xn = i + 1;
    }

    if(x1 && xn) {
        cout << "? " << x1 << " " << xn << endl;
        cout.flush();

        int kek;
        cin >> kek;
        if(kek < n - 1) {
            cout << "! A" << endl;
            cout.flush();
            return;
        }

        cout << "? " << xn << " " << x1 << endl;
        cout.flush();

        cin >> kek;
        cout << (kek < n - 1 ? "! A" : "! B") << endl;
        cout.flush();
        return;
    }
    
    sort(all(v));
    unique(all(v));

    int aux = 0;
    for(int i = 0; i < n; i++) 
        if(v[i] != i + 1) {
            aux = i + 1;
            break;
        }
    
    if(aux) {
        if(aux + 2 <= n) {

            cout << "? " << aux << " " << aux + 1 << endl;
            cout.flush();   

            int res;
            cin >> res;

            if(res != 0) {
                cout << "! B" << endl;
                return;
            }

            cout << "? " << aux << " " << aux + 2 << endl;
            cout.flush();

            cin >> res;

            if(res != 0) {
                cout << "! B" << endl;
                return;
            }

            cout << "! A" << endl;
            cout.flush();
        }
        else {
            cout << "? " << aux << " " << aux - 1 << endl;
            cout.flush();   

            int res;
            cin >> res;

            if(res != 0) {
                cout << "! B" << endl;
                return;
            }

            cout << "? " << aux << " " << aux - 2  << endl;
            cout.flush();

            cin >> res;

            if(res != 0) {
                cout << "! B" << endl;
                return;
            }

            cout << "! A" << endl;
            cout.flush();

        }
        return;
    }



}
 
int32_t main() {
    int ct = 1;
    cin >> ct;
    while(ct--)
        solve();
}