#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, k;
    cin >> n >> k;
    vector<pair<ll,ll>> ab(n);
    rep(i,n) cin >> ab[i].first;
    rep(i,n) cin >> ab[i].second;
    sort(ab.begin(), ab.end(), [](const auto &x, const auto &y){
        return x.second - x.first > y.second - y.first;
    });

    ll ans = 0;
    rep(i,n){
        if(i < k) ans += ab[i].second;
        else ans += ab[i].first;
    }

    cout << ans << endl;
    
    return 0;
}