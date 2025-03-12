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

void solve(int bit, int a, int b, int relation) {
    if(bit == -1) {
        cout << "! " << a << " " << b << endl << flush;
        return;
    }

    if(!relation) {
        cout << "? " << (a | (1<<bit)) << " " << b << endl << flush;
        cin >> relation;
        if(relation == -1) {
            a |= (1<<bit);
            b |= (1<<bit);
        }
        return solve(bit - 1, a, b, 0);
    }

    if(relation == 1) {
        cout << "? " << (a | (1<<bit)) << " " << (b | (1<<bit)) << endl << flush;
        cin >> relation;
        if(relation == -1) {
            a |= (1<<bit);
            cout << "? " << a << " " << b << endl << flush;
            cin >> relation;
            return solve(bit - 1, a, b, relation);
        }
        else {
            cout << "? " << a << " " << (b | (1<<bit)) << endl << flush;
            cin >> relation;
            if(!relation) {
                a |= (1<<bit);
                return solve(bit - 1, a, b, 0);
            }
            if(relation == 1) {
                a |= (1<<bit);
                b |= (1<<bit);
            }
            return solve(bit - 1, a, b, 1);
        }

    }

    else {
        cout << "? " << (a | (1<<bit)) << " " << (b | (1<<bit)) << endl << flush;
        cin >> relation;
        if(relation == 1) {
            b |= (1<<bit);
            cout << "? " << a << " " << b << endl << flush;
            cin >> relation;
            return solve(bit - 1, a, b, relation);
        }
        else {
            cout << "? " << (a | (1<<bit)) << " " << b << endl << flush;
            cin >> relation;
            if(!relation) {
                b |= (1<<bit);
                return solve(bit, a, b, 0);
            }
            if(relation == -1) {
                a |= (1<<bit);
                b |= (1<<bit);
            }
            return solve(bit - 1, a, b, -1);
        }

    }
}

int32_t main() {
    int relation;
    cout << "? 0 0" << endl << flush;
    cin >> relation;

    solve(29, 0, 0, relation);
}