#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    ll n, k;
    cin >> n >> k;
    ll ans = k * (k + 1) / 2;
    unordered_set<ll> s;
    rep(i,n){
        ll a;
        cin >> a;
        if(a <= k) s.insert(a);
    }

    for(ll x : s) ans -= x;
    cout << ans << endl;
    
    return 0;
}