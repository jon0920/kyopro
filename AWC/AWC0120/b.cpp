#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, k, d;
    cin >> n >> k >> d;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    vector<ll> sum(n + 1);
    rep(i,n) sum[i + 1] = sum[i] + a[i];

    ll ans = -1e18;
    rep(i,n - k + 1){
        if(d > i && d <= i + k){
            ans = max(ans, sum[i + k] - sum[i]);
        }
    }
    cout << ans << endl;
    
    return 0;
}