#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    ll n, t;
    cin >> n >> t;
    ll ans = 1e18;
    rep(i,n){
        ll a;
        cin >> a;
        if(t % a == 0) ans = min(ans, (t / a) * a);
        else ans = min(ans, ((t / a) + 1) * a);
    }

    cout << ans << endl;
    
    return 0;
}