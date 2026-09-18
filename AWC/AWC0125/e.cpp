#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, m;
    cin >> n >> m;
    vector<ll> v(n), w(n);
    rep(i,n) cin >> v[i] >> w[i];
    vector<ll> t(m);
    rep(i,m) cin >> t[i];

    int ans = 0;
    rep(bit, 1 << n){
        vector<ll> x;
        rep(i,n){
            if((bit >> i) & 1) x.push_back(v[i]);
            else x.push_back(w[i]);
        }

        vector<ll> base;
        for(ll val : x){
            for(ll e : base) val = min(val, val ^ e);
            if(val != 0) base.push_back(val);
        }
        
        bool ok = true;
        for(ll val : t){
            for(ll e : base) val = min(val, val ^ e);
            if(val != 0) ok = false;
        }
        if(ok) ans++;
    }
    cout << ans << endl;
    
    return 0;
}