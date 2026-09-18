#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    ll d;
    cin >> d;

    ll ans = d;
    for(ll x = 0; x < 2000000; x++){
        if(d <= x * x) ans = min(ans, x * x - d);
        else{
            ll y = sqrt(d - x * x);
            ans = min(ans, abs(x * x + y * y - d));
            ans = min(ans, abs(x * x + (y + 1) * (y + 1) - d));
        }
    }
    cout << ans << endl;
    
    return 0;
}