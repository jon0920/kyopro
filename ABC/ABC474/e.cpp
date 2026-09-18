#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        vector<ll> a(n), b(n), d(n);
        ll ans = 0;
        rep(i,n){
            cin >> a[i] >> b[i];
            ans += a[i];
            d[i] = b[i] - a[i];
        }
        ll mn = *min_element(a.begin(), a.end());
        sort(d.begin(), d.end());

        ll cur = ans;
        for(ll i = 1; i <= n; i++){
            cur += d[i - 1];
            ans = min(ans, cur + max(0LL, 2 * i - n) * mn);
        }
        cout << ans << endl;
    }
    
    return 0;
}