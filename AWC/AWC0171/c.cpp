#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    ll sum = 0;
    rep(i,n){
        cin >> a[i];
        sum += a[i];
    }

    if(sum <= k){
        if(sum < k) cout << 0 << endl;
        else cout << 1 << endl;
        return 0;
    }
    
    ll t = sum - k;

    ll cur = 0;
    int r = 0;
    int ans = 0;
    for(int l = 0; l < n; l++){
        while(r < n && cur < t){
            cur += a[r];
            r++;
        }
        if(cur == t) ans++;
        cur -= a[l];
    }
    
    cout << ans << endl;

    return 0;
}