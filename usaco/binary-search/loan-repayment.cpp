#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}


int32_t main() {
    setIO("loan");

    ll n, k, m;
    cin >> n >> k >> m;

    ll ini = 1, mid, end = 1e12, ans = 1;
    while(ini <= end) {
        mid = (ini + end)/2;

        ll G = 0, totDays = 0;
        while(totDays < k && G < n) {
            ll toAdd = (n - G)/mid;
            if(toAdd <= m) {
                
                if((n - G + m - 1)/m <= (k - totDays)) 
                    G = n;

                break;
            }

            ll maxG =  n - toAdd * mid;
            ll addDays = min((n - k), (maxG - G)/toAdd + 1);

            totDays += addDays;
            G += addDays * toAdd;
            
        }

        if(G >= n) {
            ans = max(ans, mid);
            ini = mid + 1;
        }
        else end = mid - 1;

    }
    cout << ans << endl;

}