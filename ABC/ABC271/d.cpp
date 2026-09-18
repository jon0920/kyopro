#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, s;
    cin >> n >> s;
    vector<pair<int,int>> ab(n);
    rep(i,n) cin >> ab[i].first >> ab[i].second;

    vector<vector<bool>> dp(n + 1, vector<bool>(s + 1));
    dp[0][0] = true;
    rep(i,n){
        auto [x, y] = ab[i];
        rep(j,s + 1){
            if(dp[i][j]){
                if(j + x <= s) dp[i + 1][j + x] = true;
                if(j + y <= s) dp[i + 1][j + y] = true;
            }
        }
    }

    if(!dp[n][s]) cout << "No" << endl;
    else {
        cout << "Yes" << endl;
        string res = "";
        int last = s;
        for(int i = n - 1; i >= 0; i--){
            auto [x, y] = ab[i];
            if(last - x >= 0 && dp[i][last - x]){
                last -= x;
                res += 'H';
            } else {
                last -= y;
                res += 'T';
            }
        }
        reverse(res.begin(), res.end());
        cout << res << endl;
    }
    
    return 0;
}