#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

using mint = modint1000000007;

int main(){
    
    ll n, a, b;
    cin >> n >> a >> b;

    mint tot = mint(2).pow(n) - 1;
    
    auto calc = [&](ll x){
        mint p = 1, q = 1;
        for(ll i = n; i > n - x; i--) p *= i;
        for(ll i = 1; i <= x; i++) q *= i;
        mint q_inv = q.inv();
        return p * q_inv;
    };

    mint ans = tot - calc(a) - calc(b);
    cout << ans.val() << endl;
    
    return 0;
}