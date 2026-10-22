#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    map<ll,ll> mp;
    ll sum = 0;
    rep(i,n){
        sum += a[i];
        mp[sum]++;
    }

    ll cur = 0;
    ll ans = 0;
    rep(i,n){
        if(mp.count(k + cur)) ans += mp[k + cur];
        cur += a[i];
        mp[cur]--;
    }

    cout << ans << endl;
    
    return 0;
}