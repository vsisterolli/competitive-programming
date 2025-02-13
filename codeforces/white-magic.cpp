#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> v(n), mn(n), suf_mex(n);
    vector<int> aux;

    int ans = 0;
    for(int &i : v) {
        cin >> i;
        ans += (i != 0);
    }
    if(n == 1) {
        cout << 1 << endl;
        return;
    }

    int hz = false;
    for(int i = 0; i < n; i++) {
        if(!v[i] && !hz) {
            aux.push_back(0);
            hz = 1;
        }
        else if(v[i])
            aux.push_back(v[i]);
    }
    v = aux;
    n = v.size();
    if(n == 1) {
        cout << 1 << endl;
        return;
    }

    int ok = 0;
    vector<bool> used(n + 1, 0);

    int mex = 0;
    for (int i = n - 1; i >= 1; i--) {
        if (v[i] <= n) {
            used[v[i]] = true;
        }
        while (used[mex]) mex++;
        suf_mex[i] = mex;
    }

    int flag = hz;
    for(int i = 0; i < n; i++) {
        mn[i] = v[i];
        if(i)
            mn[i] = mn[i - 1];
        
        if(mn[i] < suf_mex[i + 1])
            flag = false;
    }


    cout << ans + flag << endl;
}
 
int32_t main() {
    int ct = 1;
    cin >> ct;
    while(ct--)
        solve();
}