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
    setIO("traffic");
    int n;
    cin >> n;

    int mnsum = 0, mxsum = 0;
    int mxp = INF, mnp = 0;

    string s[n];
    int l[n], r[n];

    for(int i = 0; i < n; i++) {

        cin >> s[i] >> l[i] >> r[i];

        if(s[i] == "on") {
            mnsum += l[i];
            mxsum += r[i];
        }

        else if(s[i] == "off") {
            mnsum -= r[i];
            mxsum -= l[i];
        }
        
        else {
            mxp = min(mxp, r[i] - mnsum);
            mnp = max(mnp, l[i] - mxsum);
        }
    }

    cout << mnp << " " << mxp << endl;

    mnsum = 0, mxsum = 0;
    mxp = INF, mnp = 0;

    for(int i = n-1; i >=0 ; i--) {
        
        if(s[i] == "off") {
            mnsum += l[i];
            mxsum += r[i];
        }

        else if(s[i] == "on") {
            mnsum -= r[i];
            mxsum -= l[i];
        }
        
        else {
            mxp = min(mxp, r[i] - mnsum);
            mnp = max(mnp, l[i] - mxsum);
        }
    
    }

    cout << mnp << " " << mxp << endl;
}

