#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, k;
    cin >> n >> k;
    vector<int> a(k);
    rep(i,k) cin >> a[i];

    ll ans = 0;
    if(k % 2 == 0){
        for(int i = 0; i < k; i += 2) ans += a[i + 1] - a[i];
    } else {
        vector<ll> pre(k + 2), suf(k + 2);
        for(int i = 1; i < k; i += 2){
            pre[i + 1] = pre[i - 1] + (a[i] - a[i - 1]);
        }
        for(int i = k - 2; i >= 0; i -= 2){
            suf[i] = suf[i + 2] + (a[i + 1] - a[i]);
        }
        ans = 1e18;
        for(int i = 0; i < k; i += 2){
            ll cost = 0;
            if(i > 0) cost += pre[i];
            if(i < k - 1) cost += suf[i + 1];
            ans = min(ans, cost);
        }
    }
    
    cout << ans << endl;
    
    return 0;
}