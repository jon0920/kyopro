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

mint ncr(int n, int r){
    if(r < 0 || r > n || n < 0) return 0;
    return fact[n] * invfact[r] * invfact[n - r];
}

int main(){
    
    int a, b, c;
    cin >> a >> b >> c;
    int mx = max(a, c);
    mint ans = 0;

    for(int i = 1; i <= mx; i++){
        int k1 = 2 * i - 1;
        if(k1 <= b){
            mint w1 = mint(2) * ncr(a - 1, i - 1) * ncr(c - 1, i - 1);
            ans += w1 * ncr(a + b + c - k1, b - k1);
        }

        int k2 = 2 * i;
        if(k2 <= b){
            mint w2 = ncr(a - 1, i) * ncr(c - 1, i - 1) + ncr(a - 1, i - 1) * ncr(c - 1, i);
            ans += w2 * ncr(a + b + c - k2, b - k2);
        }
    }

    cout << ans.val() << endl;
    
    return 0;
}