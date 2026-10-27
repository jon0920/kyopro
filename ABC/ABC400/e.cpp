#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

const ll mx = 1000010;

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
    
    vector<ll> primes;
    primes = eratosthenes();       
    int sz = primes.size();

    vector<int> cnt(mx);
    rep(i,sz){
        ll p = primes[i];
        while(p < mx){
            cnt[p]++;
            p += primes[i];
        }
    }

    vector<ll> num;
    for(ll i = 1; i < mx; i++){
        if(cnt[i] == 2) num.push_back(i * i);
    }

    int q;
    cin >> q;
    while(q--){
        ll a;
        cin >> a;
        auto it = upper_bound(num.begin(), num.end(), a);
        it--;
        cout << *it << endl;
    }
    
    return 0;
}