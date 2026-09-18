#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    ll n, k, m;
    cin >> n >> k >> m;
    vector<ll> a(n), sum(n + 1);
    rep(i,n){
        cin >> a[i];
        sum[i + 1] = sum[i] + a[i];
    }

    ll ans = 0;
    rep(i,n-k+1){
        if(sum[i + k] - sum[i] >= m) ans += n - i - k + 1;
        else{
            int it = lower_bound(sum.begin(), sum.end(), m + sum[i]) - sum.begin();
            ans += n - it + 1;
        }
    }
    cout << ans << endl;

    return 0;
}