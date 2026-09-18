#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n;
    cin >> n;
    vector<ll> h(n);
    rep(i,n) cin >> h[i];
    sort(h.begin(), h.end());

    ll now = 0;
    ll ans = 0;
    rep(i,n){
        ans += abs(now - h[i]);
        now = h[i];
    }

    ans += abs(now - 0);
    cout << ans << endl;

    return 0;
}