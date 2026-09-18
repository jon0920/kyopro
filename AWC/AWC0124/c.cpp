#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    ll n, m;
    cin >> n >> m;
    vector<ll> r(n);
    __int128_t sum = 0;
    rep(i,n){
        cin >> r[i];
        sum += r[i];
    }
    if(sum < m){
        cout << -1 << endl;
        return 0;
    }

    ll ok = 1e18 + 10;
    ll ng = -1;

    auto check = [&](ll x) -> bool {
        ll s = 0;
        rep(i,n){
            ll t = max(0LL, r[i] - x);
            s += t;
            if(s > m) return false;
        }
        return s <= m;
    };

    while(ok - ng > 1){
        ll mid = ng + (ok - ng) / 2;
        if(check(mid)) ok = mid;
        else ng = mid;
    }

    cout << ok << endl;
    
    return 0;
}