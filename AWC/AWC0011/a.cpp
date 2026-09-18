#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    ll n, m, s, t;
    cin >> n >> m >> s >> t;
    if(s > t) swap(s,t);
    vector<pair<ll,ll>> p(m);
    rep(i,m) cin >> p[i].first >> p[i].second;
    sort(p.begin(), p.end());

    ll ans = 0;
    for(auto [a, b] : p){
        if(a >= s && a <= t){
            ans += b;
        }
    }
    cout << ans << endl;

    return 0;
}