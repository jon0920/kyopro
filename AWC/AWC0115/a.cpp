#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    cin >> n;
    vector<ll> a(n);
    ll mx = 0;
    rep(i,n){
        cin >> a[i];
        mx = max(mx, a[i]);
    }

    ll ans = 0;
    rep(i,n) ans += mx - a[i];
    cout << ans << endl;
    
    return 0;
}