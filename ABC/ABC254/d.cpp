#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    ll n;
    cin >> n;

    ll ans = 0;
    for(ll x = 1; x <= n; x++){
        ll y = x;
        for(ll d = 2; d * d <= y; d++){
            while(y % (d * d) == 0) y /= (d * d);
        }
        for(ll d = 1; d * d * y <= n; d++) ans++;
    }

    cout << ans << endl;
    
    return 0;
}