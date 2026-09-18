#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n, m, k;
    cin >> n >> m >> k;
    vector<ll> p(n), l(m);
    rep(i,n) cin >> p[i];
    rep(i,m) cin >> l[i];
    ll mx = 0;
    rep(i,k){
        int t;
        cin >> t;
        t--;
        mx = max(mx, l[t]);
    }

    ll ans = 0;
    for(auto x : p) if(mx >= x) ans+= x;
    cout << ans << endl;

    return 0;
}