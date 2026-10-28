#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, m;
    cin >> n >> m;
    vector<ll> a(n * 2);
    rep(i,n){
        ll x;
        cin >> x;
        a[i] = x;
        a[i + n] = x;
    }
    vector<ll> sum(n * 2 + 1);
    rep(i,n * 2) sum[i + 1] = sum[i] + a[i];

    ll ans = -1e18;
    rep(i,n * 2 - m + 1){
        ans = max(ans, sum[i + m] - sum[i]);
    }

    cout << ans << endl;
    
    return 0;
}