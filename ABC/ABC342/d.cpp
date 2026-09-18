#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    ll n;
    cin >> n;

    vector<ll> square;
    for(ll x = 1; x * x <= 200000; x++) square.push_back(x * x);
    reverse(square.begin(), square.end());

    vector<ll> a(n);
    rep(i,n){
        ll v;
        cin >> v;
        for(auto x : square){
            if(v % x == 0){
                a[i] = v / x;
                break;
            }
        }
    }

    map<ll,ll> mp;
    for(auto x : a){
        mp[x]++;
    }

    ll ans = 0;
    for(auto [k, v] : mp){
        if(k == 0){
            ans += (n * (n - 1) / 2) - ((n - v) * (n - v - 1) / 2);
        } else {
            ans += v * (v - 1) / 2;
        }
    }
    cout << ans << endl;
    
    return 0;
}