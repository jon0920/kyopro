#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    ll n, k;
    cin >> n >> k;
    ll ans = 0;
    rep(i,n){
        ll p;
        cin >> p;
        if(p % k == 0) ans += p;
    }
    cout << ans << endl;

    return 0;
}