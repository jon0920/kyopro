#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    ll n, k;
    cin >> n >> k;
    vector<pair<ll,ll>> ab;
    rep(i,n){
        ll a, b;
        cin >> a >> b;
        ab.push_back({b, a / b});
        ab.push_back({a % b, 1});
    }
    sort(ab.rbegin(), ab.rend());

    ll ans = 0;
    for(auto [x, y] : ab){
        ll d = min(k, y);
        ans += x * d;
        k -= d;
    }

    cout << ans << endl;

    return 0;
}