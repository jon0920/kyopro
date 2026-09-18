#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

//ミラーラビン素数判定法
ll modpow(ll base, ll exp, ll mod){
    ll res = 1;
    base %= mod;
    while(exp > 0){
        if(exp % 2 == 1) res = (ll)((__int128_t)res * base % mod);
        base = (ll)((__int128_t)base * base % mod);
        exp /= 2;
    }
    return res;
}

bool miller_rabin(ll n, int a){
    if(n % a == 0) return n == a;
    ll d = n - 1;
    while(d % 2 == 0) d /= 2;

    ll x = modpow(a, d, n);
    if(x == 1 || x == n - 1) return true;

    while(d != n - 1){
        x = (ll)((__int128_t)x * x % n);
        d *= 2;
        if(x == n - 1) return true;
        if(x == 1) return false;
    }
    return false;
}

bool is_prime(ll n){
    if(n <= 1) return false;
    if(n == 2 || n == 3) return true;
    if(n % 2 == 0 || n % 3 == 0) return false;

    for(int a : {2, 3, 5, 7, 11, 13, 17, 19, 23}){
        if(n <= a) break;
        if(!miller_rabin(n, a)) return false;
    }
    return true;
}

void solve(){
    ll n; 
    cin >> n;
    ll m = n;
    while(!is_prime(m)) m++;
    cout << m - n << endl;
}

int main(){
    
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    
    return 0;
}