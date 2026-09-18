#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

vector<pair<ll,ll>> primes(ll n){
    vector<pair<ll,ll>> res;
    for(ll p = 2; p * p <= n; p++){
        if(n % p != 0) continue;
        ll e = 0;
        while(n % p == 0){
            n /= p;
            e++;
        }
        res.push_back({p, e});
    }
    if(n != 1) res.push_back({n, 1});
    return res;
};

ll count(ll n, ll p){
    ll res = 0;
    while(n % p == 0){
        n /= p;
        res++;
    }
    return res;
};

int main(){
    
    ll k;
    cin >> k;
    vector<pair<ll,ll>> P = primes(k);

    ll ans = 0;
    for(auto [p, e] : P){
        ll f = 0;
        for(ll n = p; ; n++){
            f += count(n, p);
            if(f >= e){
                ans = max(ans, n);
                break;
            }
        }
    }
    cout << ans << endl;
    
    return 0;
}