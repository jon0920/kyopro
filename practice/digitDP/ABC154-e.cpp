#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

ll dp[110][2][4];

int main(){
    
    string N;
    int K;
    cin >> N >> K;
    int n = N.size();
    
    dp[0][0][0] = 1;
    rep(i,n){
        rep(smaller,2){
            rep(cnt,K + 1){
                int lim = smaller ? 9 : N[i] - '0';
                rep(d,lim + 1){
                    int next_smaller = smaller || (d < lim);
                    int next_cnt = cnt + (d != 0);
                    if(next_cnt > K) continue;
                    dp[i + 1][next_smaller][next_cnt] += dp[i][smaller][cnt];
                }
            }
        }
    }

    cout << dp[n][0][K] + dp[n][1][K] << endl;
    
    return 0;
}