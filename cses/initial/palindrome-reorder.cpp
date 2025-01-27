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
    string s;
    cin >> s;

    int v[26];
    memset(v, 0, sizeof v);
    
    for(char &i : s) 
        v[i - 'A']++;
    
    int aux = 0;
    for(int &i : v) 
        aux += (i & 1);
    

    if(aux > 1) {
        cout << "NO SOLUTION" << endl;
        return 0;
    }

    aux = -1;
    for(int i = 0; i < 26; i++) {
        for(int j = 0; j < v[i]/2; j++)
            cout << char(i + 'A');
        if(v[i] & 1)
            aux = i;
    }

    if(aux != -1)
        cout << char(aux + 'A');
    
    for(int i = 25; i >= 0; i--) {
        for(int j = 0; j < v[i]/2; j++)
            cout << char(i + 'A');
        if(v[i] & 1)
            aux = i;
    }

    cout << endl;
}

