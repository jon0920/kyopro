#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];

    ll ans = -1e18;
    rep(i,n){
        ll sum = 0;
        if(i - 1 >= 0) sum += a[i - 1];
        sum += a[i];
        if(i + 1 < n) sum += a[i + 1];
        ans = max(ans, sum);
    }

    cout << ans << endl;
    
    return 0;
}