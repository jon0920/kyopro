#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    ll n, m, d;
    cin >> n >> m >> d;
    ll ans = 0;
    rep(i,n){
        ll t;
        cin >> t;
        if(t > m){
            ll diff = t - m;
            ans += diff / d;
            if(diff % d != 0) ans++;
        }
    }
    cout << ans << endl;

    return 0;
}