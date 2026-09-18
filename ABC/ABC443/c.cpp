#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    ll n, t;
    cin >> n >> t;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];

    if(n == 0){
        cout << t << endl;
        return 0;
    }

    ll ans = a[0];
    ll nxt = a[0] + 100;
    for(int i = 1; i < n; i++){
        if(a[i] < nxt) continue;
        else{
            ans += a[i] - nxt;
            nxt = a[i] + 100;
        }
    }
    if(nxt < t) ans += t - nxt;
    cout << ans << endl;
    
    return 0;
}