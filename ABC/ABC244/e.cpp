#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

using mint = modint998244353;

int main(){
    
    int n, m, k, s, t, x;
    cin >> n >> m >> k >> s >> t >> x;
    s--, t--, x--;

    vector<pair<int,int>> edge(m);
    rep(i,m){
        cin >> edge[i].first >> edge[i].second;
        edge[i].first--;
        edge[i].second--;
    }

    vector<vector<vector<mint>>> dp(k + 1, vector<vector<mint>>(n, vector<mint>(2, 0)));
    dp[0][s][0] = 1;

    rep(i,k){
        for(auto [u, v] : edge){
            for(int p = 0; p < 2; p++){
                if(dp[i][u][p].val() > 0){
                    if(v == x){
                        dp[i + 1][v][p ^ 1] += dp[i][u][p];
                    } else {
                        dp[i + 1][v][p] += dp[i][u][p];
                    }
                }
                if(dp[i][v][p].val() > 0){
                    if(u == x){
                        dp[i + 1][u][p ^ 1] += dp[i][v][p];
                    } else {
                        dp[i + 1][u][p] += dp[i][v][p];
                    }
                }
            }
        }
    }

    cout << dp[k][t][0].val() << endl;
    
    return 0;
}

/*
制約が小さい、答えをmodで出力->DPなんじゃね？
dp[i][j][k] := i回移動してjにいるときの、xを通った偶奇をkとしたときの数
*/