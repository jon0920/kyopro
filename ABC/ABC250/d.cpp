#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

ll mx = 1'000'000;

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

    ll n;
    cin >> n;
    int sz = primes.size();
    int ans = 0;
    for(int i = 1; i < sz; i++){
        ll q = primes[i];
        ll q3 = q * q * q;
        if(q3 >= n) break;
        for(int j = 0; j < i; j++){
            __int128_t res = q3 * primes[j];
            if(res > n) break;
            else ans++;
        }
    }

    cout << ans << endl;
    
    return 0;
}