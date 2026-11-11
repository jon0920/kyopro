#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    cin >> n;
    map<ll,ll> mp;
    rep(i,n){
        ll a, b;
        cin >> a >> b;
        mp[a - b]++;
    }

    ll ans = 0;
    for(auto [k, v] : mp){
        ans += v * (v - 1) / 2;
    }
    cout << ans << endl;
    
    return 0;
}