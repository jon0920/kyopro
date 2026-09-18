#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    ll n, d;
    cin >> n >> d;
    ll ans = 0;
    rep(i,n){
        ll a, b;
        cin >> a >> b;
        ans += a + b * d;
    }

    cout << ans << endl;
    
    return 0;
}