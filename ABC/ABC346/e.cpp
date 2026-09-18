#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int h, w, m;
    cin >> h >> w >> m;
    map<int,ll> ans;
    vector<tuple<int,int,int>> tp(m);
    rep(i,m){
        int t, a, x;
        cin >> t >> a >> x;
        tp[i] = {t, a, x};
    }

    ll r_cnt = 0, c_cnt = 0;
    vector<bool> r(h), c(w);
    for(int i = m - 1; i >= 0; i--){
        auto [t, a, x] = tp[i];
        a--;
        if(t == 1){
            if(r[a]) continue;
            ans[x] += w - c_cnt;
            r_cnt++;
            r[a] = true;
        } else {
            if(c[a]) continue;
            ans[x] += h - r_cnt;
            c_cnt++;
            c[a] = true;
        }
    }

    ans[0] += (h - r_cnt) * (w - c_cnt);

    int cnt = 0;
    for(auto [k, v] : ans){
        if(v > 0) cnt++;
    }

    cout << cnt << endl;
    for(auto [k, v] : ans){
        if(v > 0) cout << k << " " << v << endl;
    }
    
    return 0;
}