#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    cin >> n;
    vector<ll> a(n), sum(n + 1);
    rep(i,n){
        cin >> a[i];
        sum[i + 1] = sum[i] + a[i];
    }

    ll ans = 1e18;
    for(int i = 1; i < n; i++){
        ll l = sum[i] - sum[0];
        ll r = sum[n] - sum[i];
        ans = min(ans, abs(l - r));
    }

    cout << ans << endl;
    
    return 0;
}