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
    
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    mint sum = 0;
    mint sum2 = 0;
    rep(i,n){
        cin >> a[i];
        sum += a[i];
        sum2 += a[i] * a[i];
    }

    mint ans = sum2 * nCr(n - 1, k - 1) + (sum * sum - sum2) * nCr(n - 2, k - 2);
    cout << ans.val() << endl;

    return 0;
}