#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];

    ll sum = 0, ans = 0;
    int r = -1;
    for(int l = 0; l < n; l++){
        while(r + 1 < n && sum + a[r + 1] <= k){
            r++;
            sum += a[r];
        }
        ans += r - l + 1;
        sum -= a[l];
    }

    cout << ans << endl;

    return 0;
}