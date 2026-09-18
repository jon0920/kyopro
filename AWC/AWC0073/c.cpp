#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, d;
    cin >> n >> d;
    vector<pair<ll,ll>> xs(n);
    rep(i,n) cin >> xs[i].first >> xs[i].second;
    sort(xs.begin(), xs.end());
    
    vector<ll> x(n), s(n), sum(n + 1);
    rep(i,n){
        x[i] = xs[i].first;
        s[i] = xs[i].second;
        sum[i + 1] = sum[i] + s[i];
    }

    ll ans = 0;
    rep(i,n-1){
        int it = upper_bound(x.begin(), x.end(), x[i] + d) - x.begin();
        it--;
        ans += s[i] * (sum[it + 1] - sum[i + 1]);
    }

    cout << ans << endl;
    
    return 0;
}