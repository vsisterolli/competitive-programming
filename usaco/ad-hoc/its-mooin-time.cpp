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
    int n, f;
    cin >> n >> f;

    string v;
    cin >> v;

    vector<char> aux;
    for(char c1 = 'a'; c1 <= 'z'; c1++)
        for(char c2 = 'a'; c2 <= 'z'; c2++) {
            if(c1 == c2)
                continue; 
            
            int x = 0, mb = 0;
            for(int i = 0; i + 2 < n; i++) {
                if(v[i] == c1 && v[i+1] == c2 && v[i+2] == c2)
                    x++;
            }

            if(x >= f) {
                aux.pb(c1); aux.pb(c2); aux.pb(c2);   
                continue;
            }

            for(int i = 0; i < n; i++) {
                
                if(i + 2 < n && v[i] == c1 && v[i + 1] == c2 && v[i+2] == c2)
                    continue;
            
                if(i - 1 >= 0 && i + 1 < n && v[i-1] == c1 && v[i] == c2 && v[i+1] == c2)
                    continue;

                if(i - 2 >= 0 && v[i-2] == c1 && v[i - 1] == c2 && v[i] == c2)
                    continue;
                
                char backup = v[i];
                v[i] = c1;

                if(i + 2 < n && v[i] == c1 && v[i + 1] == c2 && v[i+2] == c2) {
                    x++;
                    v[i] = backup;
                    break;
                }
            
                if(i - 1 >= 0 && i + 1 < n && v[i-1] == c1 && v[i] == c2 && v[i+1] == c2) {
                    x++;
                    v[i] = backup;
                    break;
                }

                if(i - 2 >= 0 && v[i-2] == c1 && v[i - 1] == c2 && v[i] == c2) {
                    x++;
                    v[i] = backup;
                    break;
                }

                v[i] = c2;

                if(i + 2 < n && v[i] == c1 && v[i + 1] == c2 && v[i+2] == c2) {
                    x++;
                    v[i] = backup;
                    break;
                }
            
                if(i - 1 >= 0 && i + 1 < n && v[i-1] == c1 && v[i] == c2 && v[i+1] == c2) {
                    x++;
                    v[i] = backup;
                    break;
                }

                if(i - 2 >= 0 && v[i-2] == c1 && v[i - 1] == c2 && v[i] == c2) {
                    x++;
                    v[i] = backup;
                    break;
                }

                v[i] = backup;
            }

            if(x >= f)  {
                aux.pb(c1); aux.pb(c2); aux.pb(c2);   
            }
        }

    cout << aux.size()/3 << endl;
    for(int i = 0; i < aux.size(); i += 3) {
        cout << aux[i] << aux[i+1] << aux[i+2] << endl;
    }
}

