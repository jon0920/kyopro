#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    cin >> n;
    vector<pair<ll,ll>> pt(n);
    rep(i,n){
        ll t, p;
        cin >> t >> p;
        pt[i] = {p, t};
    }
    sort(pt.begin(), pt.end(), [](const auto &a, const auto &b){
        return a.second * b.first < a.first * b.second;
    });

    ll time = 0;
    ll ans = 0;
    for(auto [p, t] : pt){
        ans += time * p;
        ans += t * p;
        time += t;
    }

    cout << ans << endl;
    
    return 0;
}