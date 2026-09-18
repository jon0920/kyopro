#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n, k;
    cin >> n >> k;
    vector<ll> h(n);
    rep(i,n) cin >> h[i];
    sort(h.rbegin(), h.rend());

    ll ans = 0;
    rep(i,n){
        if(i < k){
            ans++;
        }
        else ans += h[i];
    }
    cout << ans << endl;

    return 0;
}