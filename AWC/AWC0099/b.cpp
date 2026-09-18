#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, m;
    cin >> n >> m;
    map<ll,ll> mp;
    rep(i,m){
        ll s, r;
        cin >> s >> r;
        mp[r] = max(mp[r], s);
    }

    ll mx = 0;
    for(auto [k, v] : mp){
        mx = max(mx, v);
        mp[k] = mx;
    }

    ll ans = 0;
    rep(i,n){
        ll t;
        cin >> t;
        auto it = mp.upper_bound(t);
        if(it == mp.begin()) continue;
        it--;
        ans += it->second;
    }

    cout << ans << endl;
    
    return 0;
}