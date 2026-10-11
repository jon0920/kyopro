#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    ll n, w;
    cin >> n >> w;
    vector<ll> a(n), b(n);
    rep(i,n) cin >> a[i] >> b[i];

    ll ans = 0;
    for(int bit = 0; bit < (1 << n); bit++){
        ll sum_a = 0, sum_b = 0;
        rep(i,n){
            if((bit >> i) & 1){
                sum_a += a[i];
                sum_b += b[i];
            }
        }
        if(sum_b <= w) ans = max(ans, sum_a);
    }

    cout << ans << endl;
    
    return 0;
}