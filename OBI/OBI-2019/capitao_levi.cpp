#include <bits/stdc++.h>
#define pb push_back
#define INF 0x3f3f3f3f3f3f3f3f
#define ll long long int
using namespace std;

typedef pair<long long, long long> pii;

ll merge_sort(vector<ll> &v){

    if(v.size()==1) return 0;
    vector<ll> u1, u2;

    for(int i=0;i<v.size()/2;i++)
        u1.push_back(v[i]);

    for(int i=v.size()/2;i<v.size();i++)
        u2.push_back(v[i]);

    ll inv = 0;
    inv+=merge_sort(u1);
    inv+=merge_sort(u2);

    u1.push_back(INF);
    u2.push_back(INF);

    int id=0, id2=0;
    for(int i=0;i<v.size();i++){
        if(u1[id]< u2[id2]){
            v[i]=u1[id];
            id++;
        }
        else {
            v[i]=u2[id2];
            id2++;
            inv+=u1.size()-id-1;
        }
    }
    return inv;
}

int main() {
    long long int n, p, q;
    cin >> n >> p >> q;
    vector<pii> aux;
    vector<ll> pontos;
    for(int i = 0; i < n; i++) {
        ll x, y;
        cin >> x >> y;
        if(q < 0) aux.pb(pii(x, -(q*y-p*x)));
        else aux.pb(pii(x, q*y-p*x));
    }

    sort(aux.begin(), aux.end(), greater<pii>() );
    for(int i = 0; i < aux.size(); i++)
        pontos.pb(aux[i].second);

    ll ans = merge_sort(pontos);
    cout << ans << endl;
}
