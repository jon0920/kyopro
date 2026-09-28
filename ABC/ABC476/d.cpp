#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    ll n, m, k;
    ll x, y;
    cin >> n >> m >> k >> x >> y;
    ll tot = x + k * y;
    vector<ll> a(n), b(m);
    rep(i,n) cin >> a[i];
    rep(i,m) cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    vector<ll> a_sum(n + 1), b_sum(m + 1);
    rep(i,n) a_sum[i + 1] = a_sum[i] + a[i];
    rep(i,m) b_sum[i + 1] = b_sum[i] + b[i];

    vector<ll> k_sum(m + 1);
    rep(i,m){
        k_sum[i + 1] = k_sum[i] + (b[i] + k - 1) / k;
    }

    int ans = 0;
    rep(i,m + 1){
        if(y < k_sum[i]) break;
        ll rem = tot - b_sum[i];
        if(rem < 0) break;
        int j = upper_bound(a_sum.begin(), a_sum.end(), rem) - a_sum.begin() - 1;
        ans = max(ans, i + j);
    }

    cout << ans << endl;
    
    return 0;
}