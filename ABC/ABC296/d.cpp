#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

const ll mx = 1000010;

int main(){
    
    ll n, m;
    cin >> n >> m;
    
    ll ans = 4e18;
    for(ll x = 1; x <= mx; x++){
        ll y = (m + x - 1) / x;
        if(x <= n && y <= n) ans = min(ans, x * y);
    }

    if(ans == 4e18){
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
    
    return 0;
}