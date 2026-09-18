#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, m;
    cin >> n >> m;
    vector<pair<ll,ll>> event;
    rep(i,n){
        ll x, c;
        cin >> x >> c;
        x--;
        event.push_back({x, c});
    }
    rep(i,m){
        ll l, r;
        cin >> l >> r;
        l--;
        event.push_back({l,-1});
        event.push_back({r,-2});
    }
    sort(event.begin(), event.end());
    
    int cur = 0;
    ll ans = 0;
    for(auto [_, c] : event){
        if(c == -1) cur++;
        else if(c == -2) cur--;
        else if(cur > 0) ans += c;
    }

    cout << ans << endl;
    
    return 0;
}