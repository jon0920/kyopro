#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

using mint = modint998244353;

const int MAX = 3000005;
mint fact[MAX], invfact[MAX];

void pre(){
    fact[0] = 1;
    for(int i = 1; i < MAX; i++) fact[i] = fact[i - 1] * i;
    invfact[MAX - 1] = fact[MAX - 1].inv();
    for(int i = MAX - 2; i >= 0; i--) invfact[i] = invfact[i + 1] * (i + 1);
}

mint nCr(int n, int r){
    if(r < 0 || r > n || n < 0) return 0;
    return fact[n] * invfact[r] * invfact[n - r];
}

int main(){
    
    pre();
    ll x1, x2, x3;
    cin >> x1 >> x2 >> x3;
    ll n = x1 + x2 + x3;

    mint ans = 0;
    for(ll i = 1; i < x1; i++){
        ans += nCr(x1 - 1, i) * nCr(x3 - 1, i - 1) * nCr(n - i * 2, x1 + x3);
    }

    for(ll i = 1; i < x3; i++){
        ans += nCr(x3 - 1, i) * nCr(x1 - 1, i - 1) * nCr(n - i * 2, x1 + x3);
    }

    for(ll i = 1; i <= min(x1, x3); i++){
        ans += 2 * nCr(x1 - 1, i - 1) * nCr(x3 - 1, i - 1) * nCr(n - (i * 2 - 1), x1 + x3);
    }

    cout << ans.val() << endl;
    
    return 0;
}