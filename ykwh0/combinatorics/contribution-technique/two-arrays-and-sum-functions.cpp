#pragma GCC optimize("Ofast", "unroll-loops")  
#pragma GCC target("avx2")  

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

template <class K, class V>
using ht =
    gp_hash_table<K, V, hash<K>, equal_to<K>, direct_mask_range_hashing<>,
                  linear_probe_fn<>,
                  hash_standard_resize_policy<hash_exponential_size_policy<>,
                                              hash_load_check_resize_trigger<>, true>>;

map<string, string> translation;
map<string, bool> notEnd;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    cin.ignore();           // eat the leftover newline once, before the loop
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;

        string t;
        cin.ignore(1, ' ');        // eat the space before the translation
        std::getline(cin, t);      // now t is the rest of the line

        translation[s] = t;

        string aux = "";
        for(char ch : s) {
            notEnd[aux] = true;
            aux.push_back(ch);
        }
    }

    string tt;
    cin >> tt;

    int li = 0;
    string cur = "", last = "";
    for(int i = 0; i <= tt.size(); i++) {
        if(i == tt.size()) {
            auto it = translation.find(cur);
            if(it == translation.end()) {
                cout << last << " ";
                cur = "";
                last = "";
                i = li;
                continue;
            }
            break;
        }
        cur.push_back(tt[i]);
        auto it = translation.find(cur);
        if(it != translation.end()) {
            last = it->second;
            li = i;
        } else if(notEnd.find(cur) == notEnd.end()) {
            cout << last << " ";
            cur = "";
            last = "";
            i = li;
        }
    }
    if(translation.find(cur) != translation.end()) 
        last = translation[cur];

    cout << last << '\n';
}