void sieve() {
    for(int i = 1; i < MAXN; i++)
        phi[i] = i;

    for(int i = 2; i < MAXN; i++)
        if(phi[i] == i)
            for(int j = i; j < MAXN; j+= i)
                phi[j] -= phi[j]/i;
}

int singlePhi(int x) {
    int ans = x;

    for(int i = 2; i * i <= x; i++) {
        if(x % i == 0)
            ans -= ans/i;
        while(x % i == 0)
            x /= i;
    }

    if(x > 1)
        ans -= ans/x;

    return ans;
}
