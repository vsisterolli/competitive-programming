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
#define int long long
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
const ll mod = 1e9 + 7, MAXN = 2e5 + 5;
typedef vector<int> vi;
typedef pair<int, pair<int, int>> piii;

array<int, 3> euclides(int a, int b) {
    if (!b)
        return {1, 0, a};

    array<int, 3> prev = euclides(b, a % b);
    return {prev[1], prev[0] - (a / b) * prev[1], prev[2]};
}

int crt(vector<int> &A, vector<int> &M) {

    if(!A.size() || A.size() != M.size())
        return -1;
    
    int a = A[0], m = M[0], n = A.size();
    for(int i = 1; i < n; i++) {

        array<int, 3> sol = euclides(m, M[i]);
        if( (a % sol[2]) != (A[i] % sol[2]) )
            return -1;

        int nMod = ((__int128_t)m * M[i]) / sol[2];

        int p1 = ((__int128_t) a * (M[i]/sol[2]) ) % nMod;
        p1 = ((__int128_t) p1 * sol[1]) % nMod;
   
        int p2 = ((__int128_t)A[i] * (m/sol[2])) %nMod;
        p2 = ((__int128_t)p2 * sol[0]) % nMod;
    
        a = (p1 + p2) % nMod;
        if (a < 0) a += nMod;
        m = nMod;
    }

    return a;
}