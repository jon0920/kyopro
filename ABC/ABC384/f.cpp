#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    ll n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];

    int K = 25;
    vector<ll> cur(K + 1);
    rep(k,K){
        ll kk = 1 << k;
        unordered_map<ll, pair<ll,ll>> mp;
        for(auto i : a){
            auto [c1, c2] = mp[(kk - i) % kk];
            mp[(kk - i) % kk] = {c1 + 1, c2 + i};
            c1 = mp[i % kk].first;
            c2 = mp[i % kk].second;
            cur[k] = c2 + i * c1;
        }
    }

    ll ans = 0;
    rep(i,K){
        ans += (cur[i] - cur[i + 1]) >> i;
    }

    cout << ans << endl;

    return 0;
}