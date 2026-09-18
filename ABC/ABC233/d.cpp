#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    vector<ll> s(n + 1);
    map<ll,ll> mp;
    mp[0] = 1;
    ll sum = 0;
    rep(i,n){
        cin >> a[i];
        s[i + 1] = s[i] + a[i];
        sum += a[i];
        mp[sum]++;
    }

    ll ans = 0;
    for(auto x : s){
        mp[x]--;
        if(mp.count(x + k)){
            ans += mp[x + k];
        }
    }

    cout << ans << endl;
    
    return 0;
}