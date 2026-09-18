#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    ll n, t, c, d;
    cin >> n >> t >> c >> d;

    ll ans = 0, cnt = 0;
    rep(i,n){
        ll w;
        cin >> w;
        if(w >= t){
            ans += d;
            cnt++;
        }
    }

    ll x = ans;
    while(cnt--){
        x -= d;
        x += c;
        ans = min(ans, x);
    }
    cout << ans << endl;

    return 0;
}