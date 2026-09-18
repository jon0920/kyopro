#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

const int dx[] = {-1, 0};
const int dy[] = {0, -1};

int main(){
    
    int h, w, n;
    cin >> h >> w >> n;
    vector<vector<int>> v(h, vector<int>(w));
    rep(i,n){
        int a, b;
        cin >> a >> b;
        a--, b--;
        v[a][b] = 1;
    }

    vector<vector<ll>> dp(h, vector<ll>(w));
    ll ans = 0;
    rep(i,h){
        rep(j,w){
            if(v[i][j] == 1){
                dp[i][j] = 0;
            } else {
                if(i == 0 || j == 0) dp[i][j] = 1;
                else{
                    dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
                }
            }
            ans += dp[i][j];
        }
    }

    cout << ans << endl;

    return 0;
}