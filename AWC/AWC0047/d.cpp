#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n;
    cin >> n;
    vector<ll> a(n);
    ll sum = 0;
    rep(i,n) cin >> a[i], sum += a[i];

    if(sum % n != 0){
        cout << -1 << endl;
        return 0;
    }

    ll v = sum / n;
    ll ans = 0;
    ll crr = 0;
    rep(i, n - 1){
        crr += a[i];
        ll target = v * (i + 1);

        ans += abs(target - crr);
    }

    cout << ans << endl;
    
    return 0;
}