#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

const int LOG = 30;

int main(){
    
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    rep(i,n){
        cin >> a[i];
        a[i]--;
    }

    vector<vector<pair<int,ll>>> dp(LOG, vector<pair<int,ll>>(n));
    rep(i,n){
        dp[0][i] = {a[i], i + 1};
    }
    
    for(int i = 0; i + 1 < LOG; i++){
        rep(j,n){
            auto [mid, water1] = dp[i][j];
            auto [nxt, water2] = dp[i][mid];

            dp[i + 1][j] = {nxt, water1 + water2};
        }
    }

    while(q--){
        int t, b;
        cin >> t >> b;
        b--;
        ll res = 0;
        for(int bit = 0; bit < LOG; bit++){
            if((t >> bit) & 1){
                res += dp[bit][b].second;
                b = dp[bit][b].first;
            }
        }
        cout << res << endl;
    }

    return 0;
}