#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        long double d, r;
        cin >> d >> r;

        cout << fixed << setprecision(8) << sqrt(r * r - d * d) << endl;
    }
}