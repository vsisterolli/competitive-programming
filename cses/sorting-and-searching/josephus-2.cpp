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
const ll mod = 998244353, MAXN = 2e5 + 5;
typedef vector<int> vi;
typedef pair<int, pair<int, int>> piii;
// END HEADER

int BIT[MAXN];
int N;
void update(int x,int val) { while(x<=N)  {  BIT[x]+=val;  x+=(x&-x);  } }
int query(int x) {  int res=0;  while(x>0)  {  res+=BIT[x];  x-=(x&-x);  } return res; } 

int32_t main() {
    FAST;   
    int n, k;
    cin >> n >> k;
    N = n;
    for(int i = 1; i <= n; i++)
        update(i, 1);

    int last = 0;
    for(int i = 0; i < n; i++) {
        int jump = k % (n - i);
        int toDelete = (last + jump) % (n - i);
        last = toDelete;

        int ini = 1, mid, end = n, ans = n;
        while(ini <= end) {
            int mid = (ini + end)/2;
            int upto = query(mid);
            upto--;
            
            if(upto < toDelete) 
                ini = mid + 1;
            else if(upto >= toDelete) {
                end = mid - 1;
                if(upto == toDelete)
                    ans = min(ans, mid);
            }
        }
        
        cout << ans << " ";
        update(ans, -1);
    }

}
