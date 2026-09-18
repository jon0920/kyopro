#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, m;
    cin >> n >> m;
    vector<ll> h(n);
    rep(i,n) cin >> h[i];
    rep(i,m){
        ll t, d;
        cin >> t >> d;
        t--;
        h[t] -= d;
        if(t - 1 >= 0) h[t - 1] -= d / 2;
        if(t + 1 < n) h[t + 1] -= d / 2;
    }

    int ans = 0;
    for(ll x : h) if(x >= 1) ans++;
    cout << ans << endl;
    
    return 0;
}