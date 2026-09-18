#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> h(n), p(m);
    rep(i,n) cin >> h[i];
    rep(i,m) cin >> p[i];
    sort(h.begin(), h.end());
    ll mx = *max_element(p.begin(), p.end());

    int ans = 0;
    rep(i,n){
        k -= (h[i] / mx) + 1;
        if(h[i] % mx == 0) k++;
        if(k < 0) break;
        ans++;
    }
    cout << ans << endl;
    
    return 0;
}