#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    ll n, p, q;
    cin >> n >> p >> q;
    vector<pair<ll,ll>> xc(n);
    rep(i,n) cin >> xc[i].first >> xc[i].second;
    sort(xc.begin(), xc.end());

    pair<ll,ll> ans1 = {1e18, 0}, ans2 = {1e18, 0};
    for(auto [x, c] : xc){
        if(abs(ans1.first - p) > abs(x - p)){
            ans1 = {x, c};
        }
        if(abs(ans2.first - q) > abs(x - q)){
            ans2 = {x, c};
        }
    }

    if(ans1 == ans2) cout << ans1.second + 2 << endl;
    else cout << ans1.second + ans2.second + 2 << endl;

    return 0;
}