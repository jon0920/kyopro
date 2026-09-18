#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n;
    cin >> n;
    vector<pair<ll,ll>> p;
    rep(i,n){
        ll x, l, r, c;
        cin >> x >> l >> r >> c;
        p.push_back({x - l, c});
        p.push_back({x + r, -c});
    }
    sort(p.begin(), p.end(), [](const auto &a, const auto &b){
        if(a.first != b.first) return a.first < b.first;
        return a.second > b.second;
    });

    ll ans = 0;
    ll sum = 0;
    for(auto [x, c] : p){
        sum += c;
        ans = max(ans, sum);
    }

    cout << ans << endl;

    return 0;
}