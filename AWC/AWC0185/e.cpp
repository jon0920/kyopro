#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

using mint = modint1000000007;

int main(){
    
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];

    ll LCM = 1;
    rep(i,n){
        LCM = lcm(LCM, a[i]);
    }

    mint x = LCM;
    mint y = *min_element(a.begin(), a.end());
    mint inv_y = y.inv();
    mint ans = x * inv_y;

    cout << ans.val() << endl;
    
    return 0;
}