#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    ll n, m, k;
    cin >> n >> m >> k;
    vector<pair<ll,ll>> bc(k);
    rep(i,k) cin >> bc[i].first >> bc[i].second;
    sort(bc.rbegin(), bc.rend());

    ll lim = (n * m + 1) / 2;
    ll rem = n * m;
    ll ans = 0;
    rep(i,k){
        ll cnt = min({lim, bc[i].second, rem});
        ans += cnt * bc[i].first;
        rem -= cnt;
    }

    cout << ans << endl;
    
    return 0;
}