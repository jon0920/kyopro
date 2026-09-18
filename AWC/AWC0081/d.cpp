#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    cin >> n;
    vector<ll> a(n + 1), c(n + 1);
    ll sum = 0;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> c[i], sum += c[i];

    vector<ll> dp(n + 1, 0);
    for(int i = 1; i <= n; i++){
        ll mx = 0;
        rep(j,i){
            if(a[i] > a[j]) mx = max(mx, dp[j]);
        }
        dp[i] = c[i] + mx;
    }

    cout << sum - *max_element(dp.begin(), dp.end()) << endl;
    
    return 0;
}