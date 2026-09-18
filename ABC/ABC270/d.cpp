#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, k;
    cin >> n >> k;
    vector<int> a(k);
    rep(i,k) cin >> a[i];

    vector<int> dp(n + 1);
    for(int i = 1; i <= n; i++){
        int mx = 0;
        for(int x : a){
            if(x <= i){
                mx = max(mx, i - dp[i - x]);
            }
        }
        dp[i] = mx;
    }

    cout << dp[n] << endl;
    
    return 0;
}