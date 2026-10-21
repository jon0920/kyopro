#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    ll n, k;
    cin >> n >> k;
    ll sum = 0;
    vector<pair<ll,ll>> ba(n);
    rep(i,n){
        ll a, b;
        cin >> a >> b;
        ba[i] = {b, a};
        sum += a;
    }

    if(sum < k){
        cout << -1 << endl;
        return 0;
    }

    sort(ba.rbegin(), ba.rend());

    ll ans = 0;
    rep(i,n){
        ll cnt = min(k, ba[i].second);
        ans += cnt * ba[i].first;
        k -= cnt;
    }

    cout << ans << endl;
    
    return 0;
}