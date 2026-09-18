#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, K, d;
    cin >> n >> K >> d;
    vector<vector<ll>> dp(K + 1, vector<ll>(d, -1));
    dp[0][0] = 0;

    rep(i,n){
        ll a;
        cin >> a;
        for(int j = K - 1; j >= 0; j--){
            rep(k,d){
                if(dp[j][k] == -1) continue;
                dp[j + 1][(k + a) % d] = max(dp[j + 1][(k + a) % d], dp[j][k] + a);
            }
        }
    }

    cout << dp[K][0] << endl;
    
    return 0;
}