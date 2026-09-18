#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    vector<ll> d(n - 1);
    rep(i,n - 1){
        d[i] = abs(a[i] - a[i + 1]);
    }

    int r = 0;
    int ans = 1e9;
    ll sum = 0;
    for(int l = 0; l < n - 1; l++){
        while(r < n - 1 && sum < k){
            sum += d[r];
            r++;
        }
        if(sum >= k){
            ans = min(ans, r - l + 1);
        }
        sum -= d[l];
    }

    if(ans != 1e9) cout << ans << endl;
    else cout << -1 << endl;
    
    return 0;
}