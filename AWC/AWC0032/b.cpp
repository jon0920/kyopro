#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    ll n, k, m;
    cin >> n >> k >> m;
    k += m;
    ll ans = 0;
    rep(i,n){
        ll a;
        cin >> a;
        ans += a / k;
        if(a % k != 0) ans++;
    }

    cout << ans << endl;

    return 0;
}