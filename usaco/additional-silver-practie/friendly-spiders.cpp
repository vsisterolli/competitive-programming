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
#define debug3(x, y, z) cerr << "DEBUG " << x << " " << y << " " << z << endl
#define debug4(x, y, z, o) cerr << "DEBUG " << x << " " << y << " " << z << " " << o << endl
#define all(x) x.begin(), x.end()
#define left esquerda
#define lb lower_bound
#define right direita
using namespace std;
void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}
typedef pair<ll, ll> pii;
typedef vector<vector<char>> mat;
typedef pair<int, string> pis;
const ll mod = 1e9 + 7, MAXN = 3e5 + 5;
typedef vector<int> vi;
typedef pair<int, pair<int, int>> piii;


int divisor[MAXN];
vector<int> g[2 * MAXN], dist(2 * MAXN), prevs(2 * MAXN);

void sieve() {
    divisor[0] = divisor[1] = 1;
    for(int i = 2; i < MAXN; i++)
        if(!divisor[i])
            for(int j = i; j < MAXN; j+= i)
                divisor[j] = i;
}

void solve() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {

        int x;
        cin >> x;
        while(x > 1) {
            int p = divisor[x];
            while(x % p == 0) 
                x /= p;
            g[i].pb(n + p);
            g[n + p].pb(i);
        }

    }

    int st, tg;
    cin >> st >> tg;

    queue<int> q({st});
    dist[st] = 2;
    while(!q.empty()) {
        int cur = q.front(); q.pop();

        for(int &i : g[cur])
            if(!dist[i]) {
                dist[i] = dist[cur] + 1;
                q.push(i);
                prevs[i] = cur;
            }

    }
    if(!dist[tg]) 
        cout << -1 << endl;
    else {
        cout << dist[tg]/2 << endl;
        int cur = tg;
        vector<int> ans;
        while(cur != st) {
            if(cur <= n)
                ans.push_back(cur);
            cur = prevs[cur];
        }
        ans.push_back(st);
        reverse(all(ans));
        for(int &i : ans)
            cout << i << " ";
        cout << endl;
    }
    
}

int32_t main() {
    FAST;
    sieve();
    int ct = 1;
    // cin >> ct;
    while(ct--)
        solve();
    return 0;
}