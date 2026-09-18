#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

ll mx = 10'000'000;

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
    
    int t;
    cin >> t;
    rep(ti,t){
        ll n;
        cin >> n;
        ll p, q;
        for(ll a : primes){
            if(n % a == 0){
                if((n / a) % a == 0){
                    p = a;
                    q = n / a / a;
                } else {
                    p = sqrt(n / a);
                    q = a;
                }
                cout << p << " " << q << endl;
                break;
            }    
        }
    }
    
    return 0;
}