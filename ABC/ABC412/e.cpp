#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

ll mx = 10'000'100;

vector<ll> eratosthenes(){
    vector<bool> is_prime(mx + 1, true);
    is_prime[0] = is_prime[1] = false;
    for(ll i = 2; i * i <= mx; i++){
        if(is_prime[i]){
            for(ll j = i * i; j <= mx; j += i){
                is_prime[j] = false;
            }
        }
    }
    vector<ll> P;
    for(ll i = 2; i <= mx; i++){
        if(is_prime[i]) P.push_back(i);
    }
    return P;
}

int main(){
    
    ll l, r;
    cin >> l >> r;
    vector<ll> primes = eratosthenes();
    vector<bool> check(r - l);

    int ans = 1;
    for(ll p : primes){
        if(p * p > r) break;
        ll init = max(p * p, ((l + 1 + p - 1) / p) * p);
        for(ll v = init; v <= r; v += p){
            check[v - (l + 1)] = true;
            ll w = v;
            while(w % p == 0) w /= p;
            if(w == 1) ans++;
        }
    }

    for(bool i : check) if(!i) ans++;
    cout << ans << endl;
    
    return 0;
}