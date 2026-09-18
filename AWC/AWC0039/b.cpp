#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    ll n, m, t;
    cin >> n >> m >> t;
    vector<pair<ll,ll>> P(n);
    rep(i,m){
        int c, s;
        cin >> c >> s;
        c--;
        P[c].first += s;
        P[c].second++;
    }

    int ans = 0;
    for(auto [x, y] : P){
        if(y == 0) continue;
        if(x < t * y) ans++;
    }
    cout << ans << endl;

    return 0;
}