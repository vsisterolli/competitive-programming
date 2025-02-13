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
#define debug(x) cerr << "DEBUG " << x << endl
#define debug2(x, y) cerr << "DEBUG " << x << " " << y << endl
#define debug3(x, y, z) cerr << "DEBUG " << x << " " << y << " " << z<< endl
#define debug4(x, y, z, o) cerr << "DEBUG " << x << " " << y << " " << z<< " " << o << endl
#define all(x) x.begin(), x.end()
#define left esquerda
#define int long long
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

void solve() {
    int n;
    cin >> n;
    
    string s;
    cin >> s;

    map<char, int> ap;
    for(char &i : s)
        ap[i]++;

    int l = 0;
    while(l < n && ap[s[l]] > 1) {
        ap[s[l]]--;
        l++;
    }

    int r = n - 1;
    while(r >= 0 && ap[s[r]] > 1) {
        ap[s[r]]--;
        r--;
    }
    
    cout << r - l + 1 << endl;

}

int32_t main() {
    // setIO("meetings");
    int ct = 1;    
    // cin >> ct;
    while(ct--)
        solve();
}