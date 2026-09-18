#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

using mint = modint998244353;

int main(){
    
    int n;
    cin >> n;
    vector<mint> A(n);
    rep(i,n){
        ll a;
        cin >> a;
        A[i] = a;
    }

    vector<mint> h(n + 1, 0);
    for(int i = 1; i <= n; i++){
        h[i] = h[i - 1] + mint(i).inv();
    }

    mint ans = 0;
    for(int i = 1; i <= n; i++){
        int m1 = min(i, n - i + 1);
        int m2 = max(i, n - i + 1);

        mint t1 = m1;
        mint t2 = mint(m1) * (h[m2] - h[m1]);
        mint t3 = mint(n + 1) * (h[n] - h[m2]) - (n - m2);

        mint c = t1 + t2 + t3;
        ans += A[i - 1] * c;
    }

    cout << ans.val() << endl;
    
    return 0;
}