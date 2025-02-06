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

string s;

int ans[11];

int manPow(int a, int b) {
    if(b == 0)
        return 1;
    
    if(b == 1)
        return a;

    int aux = manPow(a, b/2);
    if(b & 1)
        return aux * aux * a;
    else
        return aux * aux;
}

int solve(int i, int lim, int up5) {
    if(i == s.size()) 
        return up5;

    if(i == 0) {
        if(s[i] < '4')
            return 0;
        
        if(s[i] == '4')
            return solve(i+1, 1, 0);

        if(s[i] > '4')
            return solve(i+1, 0, 0);
    }

    if(!up5) {

        if(s[i] < '4' && lim)
            return 0;
        
        if(s[i] == '4' && lim)
            return solve(i+1, lim, 0);

        if(s[i] > '4' || !lim) {

            if(!lim) {
                int left = s.size() - i - 1;
                return solve(i + 1, 0, 0) + ('9' - '4') * manPow(10, left);
            }
            else {
                int left = s.size() - i - 1;
                return solve(i + 1, 0, 0) + solve(i + 1, 1, 1) + (s[i] - '4' - 1) * manPow(10, left);
            }

        }

    } else {
        if(!lim) {
            int left = s.size() - i - 1;
            return manPow(10, left+1);
        }
        else {
            int left = s.size() - i - 1;
            return solve(i + 1, 1, 1) + (s[i] - '0') * manPow(10, left);
        }   
    }

    return 0;
}

int32_t main() {

    FAST;
    int q;
    cin >> q;

    while(q--) {
        cin >> s;
        string s2 = "99";
        int kek = 0;
        for(int i = 2; i < s.size(); i++) {
            if(!ans[i]) {
                string backs = s;
                s = s2;
                ans[i] = solve(0, 1, 0);
                s = backs;
            }

            s2.push_back('9');
            kek += ans[i];
        }
        
        cout << kek + solve(0, 1, 0)  << endl;
    }
}

