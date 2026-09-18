#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    ll n, w;
    cin >> n >> w;
    vector<pair<ll,ll>> t;
    rep(i,n){
        ll l, w;
        cin >> l >> w;
        t.push_back({l, 1});
        t.push_back({l + w, -1});
    }
    sort(t.begin(), t.end(), [](const auto &a, const auto &b){
        if(a.first != b.first) return a.first < b.first;
        return a.second > b.second;
    });

    ll pos = 0;
    ll cur = 0;
    ll ans = 0;
    for(int i = 0; i < (int)t.size(); i++){
        if(cur == 0){
            pos = t[i].first;
            cur = t[i].second;
        } else {
            ans += t[i].first - pos;
            cur += t[i].second;
            pos = t[i].first;
        }
    }

    cout << ans << endl;

    return 0;
}