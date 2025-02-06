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

void solve() {
    int n;
    cin >> n;

    priority_queue<pii> fila;
    char ans[n];
    
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        ans[i] = ' ';    
        
        if(x == 0) {
            ans[i] = 'P';

            if(!fila.empty()) {
                pii aux = fila.top();
                fila.pop();

                ans[aux.s] = 'S';
            }

            if(!fila.empty()) {
                pii aux = fila.top();
                fila.pop();

                ans[aux.s] = 'Q';
            }

            if(!fila.empty()) {
                pii aux = fila.top();
                fila.pop();

                ans[aux.s] = 'D';
            }

            while(!fila.empty())
                fila.pop();
        }

        else fila.push({x, i});
    }  

    int S = false, Q = false, D = false;
    for(int i = 0; i < n; i++) {
        if(ans[i] == 'P') {
            int xd = (S > 0) + (Q > 0) + (D > 0);
            cout << xd;
            if(xd) {
                cout << " ";
                xd--;
            }
            if(S > 0) {
                cout << "popStack";
                S--;
            }
            if(xd) {
                cout << " ";
                xd--;
            }
            if(Q > 0) {
                cout << "popQueue";
                Q--;
            }
            if(xd)
                cout << " ";
            if(D > 0) {
                cout << "popFront";
                D--;
            }
            cout << endl;

        }

        if(ans[i] == 'Q') {
            cout << "pushQueue" << endl;
            Q++;
        }

        if(ans[i] == 'S') {
            cout << "pushStack" << endl;
            S++;
        }
        if(ans[i] == 'D') {
            cout << "pushFront" << endl;
            D++;
        }

        if(ans[i] == ' ')
            cout << "pushBack" << endl;

    }
}

int32_t main() {

    int ct = 1;
    while(ct--)
        solve();

}

