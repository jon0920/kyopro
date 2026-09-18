#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, m, l;
    cin >> n >> m >> l;
    vector<vector<int>> G_mod(l);
    vector<int> a(n);
    rep(i,n){
        cin >> a[i];
        G_mod[i % l].push_back(a[i]);
    }

    vector<vector<int>> op(l, vector<int>(m));
    rep(i,l){
        rep(j,m){
            int cnt = 0;
            for(auto x : G_mod[i]){
                cnt += (j - x + m) % m;
            }
            op[i][j] = cnt;
        }
    }

    vector<vector<int>> dp(l + 1, vector<int>(m, 1e9));
    dp[0][0] = 0;
    rep(i,l){
        rep(j,m){
            rep(k,m){
                dp[i + 1][(j + k) % m] = min(dp[i + 1][(j + k) % m], dp[i][j] + op[i][k]);
            }
        }
    }

    cout << dp[l][0] << endl;
    
    return 0;
}