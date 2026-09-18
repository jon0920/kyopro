#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, m;
    cin >> n >> m;
    vector<ll> t(n);
    rep(i,n) cin >> t[i];
    
    vector<ll> d(n + 2), s(n + 2);
    rep(i,m){
        ll p, b;
        cin >> p >> b;
        if(b >= p){
            s[1] += b - p + 1;
            d[1]++;
        } else {
            d[p - b]++;
        }
        d[p] -= 2;
        if(p + b <= n) d[p + b]++;
    }

    ll ans = -1e18;
    ll sum = 0, cur_d = 0;
    for(int i = 1; i <= n; i++){
        sum += s[i];
        sum += cur_d;
        cur_d += d[i];
        if(sum <= t[i - 1]) ans = max(ans, sum);
    }

    cout << ans << endl;
    
    return 0;
}