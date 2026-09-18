#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n, k;
    cin >> n >> k;
    vector<pair<ll,ll>> p(n);
    rep(i,n){
        ll a, b;
        cin >> a >> b;
        p[i] = {a, b};
    }

    sort(p.begin(), p.end(), [](const auto &a, const auto &b){
        auto &[ai, aj] = a;
        auto &[bi, bj] = b;
        return ai - aj > bi - bj;
    });

    ll ans = 0;
    rep(i,n){
        if(i < k) ans += p[i].second;
        else ans += p[i].first;
    }

    cout << ans << endl;

    return 0;
}