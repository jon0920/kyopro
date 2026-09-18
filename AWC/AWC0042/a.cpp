#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    ll n, k;
    cin >> n >> k;
    ll ans = 0;
    rep(i,n){
        ll a, b;
        cin >> a >> b;
        ans += (a + b) / k;
        if((a + b) % k != 0) ans++;
    }
    cout << ans << endl;

    return 0;
}