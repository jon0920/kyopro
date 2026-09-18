#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];

    map<ll,ll> mp;
    mp[0] = 1;

    ll crr_sum = 0;
    ll ans = 0;
    rep(i,n){
        crr_sum += a[i];
        ans += mp[crr_sum - k];
        mp[crr_sum]++;
    }

    cout << ans << endl;

    return 0;
}