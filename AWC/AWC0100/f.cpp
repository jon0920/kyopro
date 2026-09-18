#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    ll n, k;
    cin >> n >> k;
    vector<ll> v(n), sum(n + 1);
    rep(i,n){
        cin >> v[i];
        sum[i + 1] = sum[i] + v[i];
    }

    ll ans = 0;
    rep(i,n){
        auto it = lower_bound(sum.begin(), sum.end(), sum[i] + k);
        int res = sum.end() - it;
        ans += res;
    }

    cout << ans << endl;
    
    return 0;
}