#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

const ll INF = 1e18;

int main(){
    
    int n, k;
    cin >> n >> k;
    vector<ll> dp(k);
    rep(i,k) cin >> dp[i];

    rep(i,n - 1){
        pair<ll,int> mn1 = {INF, -1}, mn2 = {INF, -1};
        rep(j,k){
            if(mn1.first > dp[j]){
                mn2 = mn1;
                mn1.first = dp[j];
                mn1.second = j;
            } else if(mn2.first > dp[j]){
                mn2.first = dp[j];
                mn2.second = j;
            }
        }

        vector<ll> ndp(k, INF);
        rep(j,k){
            ll c;
            cin >> c;
            if(mn1.second != j){
                ndp[j] = mn1.first + c;
            } else {
                ndp[j] = mn2.first + c;
            }
        }
        dp = move(ndp);
    }

    cout << *min_element(dp.begin(), dp.end()) << endl;
    
    return 0;
}