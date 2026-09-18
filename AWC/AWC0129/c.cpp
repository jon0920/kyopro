#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, m;
    cin >> n >> m;
    vector<pair<ll,int>> event;
    rep(i,n){
        ll d;
        cin >> d;
        event.push_back({d,0});
    }
    rep(i,m){
        ll l, r;
        cin >> l >> r;
        event.push_back({l,-1});
        event.push_back({r,1});
    }
    sort(event.begin(), event.end());

    ll ans = 0;
    int cur = 0;
    for(auto [t, x] : event){
        if(x == 0){
            if(cur < 0) ans += t * 2;
            else ans += t;
        } else cur += x;
    }

    cout << ans << endl;
    
    return 0;
}