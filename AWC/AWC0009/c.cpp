#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    ll n, t, k;
    cin >> n >> t >> k;
    vector<ll> h(n);
    ll d = 1e9;
    rep(i,n){
        cin >> h[i];
        d = min(d, h[i] - 1);
    }

    for(auto &x : h) x -= d;

    int ans = 0;
    for(auto x : h) if(x <= t + k) ans++;
    cout << ans << endl;

    return 0;
}