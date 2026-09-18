#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    ll n, k, d;
    cin >> n >> k >> d;
    vector<pair<ll,ll>> ab(n);
    rep(i,n) cin >> ab[i].first >> ab[i].second;

    ll ans = 0;
    for(int bit = 0; bit < (1 << n); bit++){
        ll sum = 0, K = 0;
        rep(i,n){
            if(bit & (1 << i)){
                sum += ab[i].first;
                K += ab[i].second;
            }
        }
        ans = max(ans, sum - d * max(0LL, K - k));
    }

    cout << ans << endl;

    return 0;
}