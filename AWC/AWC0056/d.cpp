#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

const int INF = 1e9;

int main(){

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i,n) cin >> a[i];

    vector<vector<set<int>>> st(n, vector<set<int>>(k));
    vector<vector<int>> dp(n, vector<int>(k, INF));
    st[0][0].insert(a[0]);
    dp[0][0] = 0;
    for(int i = 0; i < n - 1; i++){
        rep(j,k){
            if(dp[i][j] == INF) continue;

            st[i + 1][j] = st[i][j];
            st[i + 1][j].insert(a[i]);
            dp[i + 1][j] = min(dp[i + 1][j], *st[i + 1][j].rbegin() - *st[i + 1][j].begin());

            if(j != k - 1){
                if(dp[i + 1][j + 1] > dp[i][j]) dp[i + 1][j + 1] = dp[i][j];
                st[i + 1][j + 1] = st[i][j];
            }
        }
    }

    cout << dp[n - 1][k - 1] << endl;

    return 0;
}