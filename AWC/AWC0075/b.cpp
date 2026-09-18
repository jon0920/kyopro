#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    ll sum = 0;
    rep(i,n){
        cin >> a[i];
        if(i < k) sum += a[i];
    }

    ll ans = sum;
    rep(i,n-k){
        sum += a[i + k];
        sum -= a[i];
        ans = min(ans, sum);
    }

    cout << ans << endl;
    
    return 0;
}