#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    ll n, k, x;
    cin >> n >> k >> x;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];

    int r = 0;
    ll cur = 0;
    ll ans = 0;
    rep(l,n){
        while(r < n && (r - l) < k && cur < x){
            cur += a[r];
            r++;
        }
        if(cur >= x) ans += min(n, l + k) - r + 1;
        cur -= a[l];
    }
    cout << ans << endl;
    
    return 0;
}