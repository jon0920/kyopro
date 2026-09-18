#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, k;
    cin >> n >> k;
    int lim = n - k * 2;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    vector<ll> sum(n + 1);
    rep(i,n) sum[i + 1] = sum[i] + a[i];

    vector<ll> rev_a = a;
    reverse(rev_a.begin(), rev_a.end());
    vector<ll> rev_sum(n + 1);
    rep(i,n) rev_sum[i + 1] = rev_sum[i] + rev_a[i];

    vector<ll> left(lim), right(lim);
    rep(i,lim){
        if(i == 0) left[i] = sum[i + k] - sum[i];
        else left[i] = max(left[i - 1], sum[i + k] - sum[i]);
    }
    rep(i,lim){
        if(i == 0) right[i] = rev_sum[i + k] - rev_sum[i];
        else right[i] = max(right[i - 1], rev_sum[i + k] - rev_sum[i]);
    }
    reverse(right.begin(), right.end());

    ll ans = 0;
    rep(i,lim){
        ans = max(ans, left[i] + right[i]);
    }

    cout << ans << endl;

    return 0;
}