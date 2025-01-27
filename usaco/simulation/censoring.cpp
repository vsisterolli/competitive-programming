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
    setIO("censor");
    
    string s, t;
    cin >> s >> t;

    stack<int> aux;
    for(int i = 0; i < s.size(); i++) {
        aux.push(i);

        int ptr = t.size() - 1;
        stack<int> aux2;

        while(!aux.empty() && ptr >= 0) {
            int x = aux.top();
            aux.pop();
            aux2.push(x);
            
            if(s[x] != t[ptr]) 
                break;
            
            ptr--;
        }
        

        while(ptr == -1 && !aux2.empty()) {
            s[aux2.top()] = '$';
            aux2.pop();
        }

        while(!aux2.empty()) {
            aux.push(aux2.top());
            aux2.pop();
        }
    
        
    }

    for(char &i : s)
        if(i != '$')
            cout << i;
    cout << endl;
}

