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

    setIO("swap");
    int n, k;
    cin >> n >> k;

    int a1, a2, b1, b2;
    cin >> a1 >> a2 >> b1 >> b2;

    vector<int> v(n);
    for(int i = 0; i < n; i++)
        v[i] = i + 1;

    a1--, a2--, b1--, b2--;

    int csize = 1;

    for(int i = 0; i >= 0; csize++, i++) {

        for(int j = 0; a2 - j >= a1 + j; j++)
            swap(v[a1 + j], v[a2 - j]);
        
        for(int j = 0; b2 - j >= b1 + j; j++)
            swap(v[b1 + j], v[b2 - j]);

        bool flag = false;
        for(int j = 0; j < n; j++)
            if(v[j] != j + 1) { 
                flag = true;
                break;
            }
        
        if(!flag)
            break;
    }

    k %= csize;

    for(int i = 0; i < k; i++) {

        for(int j = 0; a2 - j >= a1 + j; j++)
            swap(v[a1 + j], v[a2 - j]);
        
        for(int j = 0; b2 - j >= b1 + j; j++)
            swap(v[b1 + j], v[b2 - j]);
        
    }

    for(int &i : v)
        cout << i << endl;
}

