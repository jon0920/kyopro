#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<ll> a(n), b(n), d(n);
        ll sum = 0;
        rep(i,n){
            cin >> a[i] >> b[i];
            sum += a[i];
            d[i] = a[i] - b[i];
        }

        ll mn = *min_element(a.begin(), a.end());
        sort(d.rbegin(), d.rend());

        ll ans = sum;
        for(ll i = 1; i <= n; i++){
            sum -= d[i - 1];
            ans = min(ans, sum + max(0LL, (2 * i - n) * mn));
        }
        cout << ans << endl;
    }

    
    return 0;
}