typedef struct Cow {
    int w, x, d;
    Cow() {};
    
    bool operator<(Cow &a) {
        return x < a.x;
    }
} Cow;

void solve() {
    int n, S, sum = 0;
    cin >> n >> S;

    vector<Cow> cow(n);
    for(int i = 0; i < n; sum += cow[i].w, i++) 
        cin >> cow[i].w >> cow[i].x >> cow[i].d;
    sort(all(cow));


    vector<pii> tw(n);
    int l = 0, r = n-1;
    while(l <= r && cow[l].d == -1) {
        tw[l] = {cow[l].x, cow[l].w};
        l++;
    }

    while(l <= r && cow[r].d == 1) {
        tw[r] = {S - cow[r].x, cow[r].w};
        r--;
    }

    set<int> gl, gr;
    for(int i = l; i <= r; i++) {
        if(cow[i].d == -1)
            gl.insert(i);
        else
            gr.insert(i);
    }

    for(int i = l; i <= r; i++) {
        if(cow[i].d == -1)
            continue;

        auto aux = gl.upper_bound(i);
        if(aux == gl.end()) {

            auto aux2 = gr.lower_bound(i);
            aux2--;


            int time = (cow[*aux2].d == 1 ? S - cow[*aux2].x : cow[*aux2].x);
            tw[*aux2] = {time, cow[i].w};
            
            gr.erase(aux2);
        }
        else {
            int time = (cow[*aux].d == 1 ? S - cow[*aux].x : cow[*aux].x);
            // debug3(i, *aux, time);

            tw[*aux] = {time, cow[i].w};
        
            gl.erase(aux);
        }
    }

    // debug2(l, r);
    for(int i = r; i >= l; i--) {
        if(cow[i].d == 1)
            continue;
        
        auto aux = gr.lower_bound(i);
        if(aux == gr.begin()) {
            auto aux2 = gl.upper_bound(i);            
            int time = (cow[*aux2].d == 1 ? S - cow[*aux2].x : cow[*aux2].x);

            tw[*aux2] = {time, cow[i].w};
            
            gl.erase(aux2);
        }
        else {
            aux--;
            int time = (cow[*aux].d == 1 ? S - cow[*aux].x : cow[*aux].x);
            // debug3(i, *aux, time);

            tw[*aux] = {time, cow[i].w};
        
            gr.erase(aux);
        }
    }

    sort(all(tw));

    int cur = 0, at = 0;
    for(pii &i : tw) {
        cout << "TIME " << i.f << " WEIGHT " << i.s << endl;
        // debug3("Hi", i.f, i.s);
        cur += i.s;
        // debug2(cur, sum);
        if(cur * 2 >= sum) {
            at = i.f;
            break;
        }
    }
    // debug(at);

    int lp = l - 1, rp = l;

    int cnt = 0, ans = 0;
    debug(at);
    while(lp <= r) {
        // debug2(lp, rp);
        if(lp >= l) {
            
            if(cow[lp].d == -1) 
                cnt--;
            else 
                ans += cnt;

        }
        lp++;

        while(rp <= r && (cow[rp].x - cow[lp].x) <= 2 * at) {
            if(cow[rp].d == -1) 
                cnt++;
            rp++;
        }
    
    }
    cout << ans << endl;
}

int32_t main() {
    // setIO("meetings");
    int ct = 1;    
    // cin >> ct;
    while(ct--)
        solve();
}