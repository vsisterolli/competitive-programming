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
#define int long long
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
const ll mod = 998244353, MAXN = 2e5 + 5;
typedef vector<int> vi;
typedef pair<int, pair<int, int>> piii;
// END HEADER




int32_t main() {
    int n;
    cin >> n;

    ll total = 1ll * (n + 1) * n / 2;
    if( total & 1 ) {
        cout << "NO" << endl;
        return 0;
    }

    vector<int> s1, s2;
    int sum = 0;
    
    for(int i = 1; i <= n/2; i += 2) {
        s1.pb(i); s1.pb(n - i + 1);
        sum += i + n - i + 1;
    }
    
    for(int i = 2; i <= (n + 1)/2; i += 2) {
        s2.pb(i); 
        if(n - i + 1 != i)
            s2.pb(n - i + 1);
    }

    if(2 * sum != total) {
        int need = sum - total/2;
        if(need & 1) {
            s1.erase(find(s1.begin(), s1.end(), need));
            s2.pb(need);
        }
        else {
            if(need == 2) {
                s1.erase(s1.begin());
                s1.erase(find(s1.begin(), s1.end(), 3));
                s1.pb(2);
                s2.erase(find(s2.begin(), s2.end(), 2));
                s2.pb(1); s2.pb(3);
            }
            else {
                s1.erase(s1.begin());
                s1.erase(find(s1.begin(), s1.end(), need - 1));
                s2.pb(1);   s2.pb(need - 1);
            }
        }
    }

    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());

    cout << "YES" << endl;
    cout << s1.size() << endl;
    for(int &i : s1)
        cout << i << " ";
    cout << endl;
    
    cout << s2.size() << endl;
    for(int &i : s2)
        cout << i << " ";
    cout << endl;

}

