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
        sum += a[i];
    }
    vector<ll> s(n + 1);
    rep(i,n) s[i + 1] = s[i] + a[i];

    ll ans = sum;
    rep(i,n - k + 1){
        ans = max(ans, sum + s[i + k] - s[i]);
    }
    
    cout << ans << endl;
    
    return 0;
}