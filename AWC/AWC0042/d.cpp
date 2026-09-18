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
    mp[0]++;
    ll sum = 0;
    for(auto x : a){
        sum += x;
        mp[sum % k]++;
    }

    ll ans = 0;
    for(auto [k, v] : mp){
        ans += v * (v - 1) / 2;
    }
    cout << ans << endl;

    return 0;
}