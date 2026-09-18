#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];

    int r = 0;
    ll sum = 0;
    int ans = 0;
    for(int l = 0; l < n; l++){
        while(r < n && sum + a[r] <= k){
            sum += a[r];
            r++;
        }
        ans = max(ans, r - l);
        sum -= a[l];
    }

    cout << ans << endl;

    return 0;
}