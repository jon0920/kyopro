#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

const int INF = 1e9;

int main(){
    
    int n;
    cin >> n;
    vector<string> s(n);
    rep(i,n){
        cin >> s[i];
        reverse(s[i].begin(), s[i].end());
    }

    vector<vector<int>> white_cnt(n, vector<int>(n + 1));
    rep(i,n){
        rep(j,n){
            white_cnt[i][j + 1] = white_cnt[i][j] + (s[i][j] == '.');
        }
    }
    vector<vector<int>> black_cnt(n, vector<int>(n + 1));
    rep(i,n){
        for(int j = n; j > 0; j--){
            black_cnt[i][j - 1] = black_cnt[i][j] + (s[i][j - 1] == '#');
        }
    }

    vector<int> dp(n + 1, INF);
    dp[0] = 0;

    rep(i,n){
        vector<int> ndp(n + 1, INF);
        int mn = INF;
        rep(j,n + 1){
            mn = min(mn, dp[j]);
            int cost = white_cnt[i][j] + black_cnt[i][j];
            ndp[j] = mn + cost;
        }
        dp = ndp;
    }

    cout << *min_element(dp.begin(), dp.end()) << endl;
    
    return 0;
}