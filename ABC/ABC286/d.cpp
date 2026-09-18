#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n, x;
    cin >> n >> x;
    vector<vector<bool>> dp(n + 1, vector<bool>(x + 1, false));
    dp[0][0] = true;

    rep(i,n){
        int a, b;
        cin >> a >> b;
        rep(j,x + 1){
            if(dp[i][j]){
                for(int k = 0; k <= b; k++){
                    if(j + k * a >= x + 1) break;;
                    dp[i + 1][j + k * a] = true;
                }
            }
        }
    }
    bool ok = false;
    rep(i,n + 1){
        if(dp[i][x]) ok = true;
    }
    cout << (ok ? "Yes" : "No") << endl;

    return 0;
}