#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        
        vector<pair<int, int>> v(profits.size());
        for(int i = 0; i < profits.size(); i++)
            v[i] = {capital[i], profits[i]};
        sort(v.begin(), v.end());

        priority_queue<int> possible;
        
        int currentProject = 0;
        do {
            while(currentProject < v.size() && v[currentProject].first <= w) {
                possible.push(v[currentProject].second);
                currentProject++;
            }

            if(!possible.empty()) {
                w += possible.top();
                possible.pop();
                k--;
            }
            else break;

        } while(k > 0);

        return w;
    }
};