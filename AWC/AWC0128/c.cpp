#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, m;
    cin >> n >> m;
    vector<ll> w(n);
    ll mn = 1e18;
    rep(i,n) cin >> w[i];
    rep(i,m){
        ll c;
        cin >> c;
        mn = min(mn, c);
    }
    vector<ll> sum(n + 1);
    rep(i,n) sum[i + 1] = sum[i] + w[i];

    ll ans = 0;
    rep(i,n){
        auto first = sum.begin() + i + 1;
        auto it = upper_bound(first, sum.end(), sum[i] + mn);
        int cnt = it - first;
        ans += cnt;
    }

    cout << ans << endl;
    
    return 0;
}