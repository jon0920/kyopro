#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    cin >> n;
    vector<int> p(n), a(n), b(n);
    rep(i,n) cin >> p[i] >> a[i] >> b[i];

    vector<int> sum_b(n + 1);
    rep(i,n) sum_b[i + 1] = sum_b[i] + b[i];

    vector<vector<int>> dp(n + 1, vector<int>(1001, 0));
    for(int t = 0; t <= 1000; t++) dp[n][t] = t;

    for(int i = n - 1; i >= 0; i--){
        for(int t = 0; t <= 1000; t++){
            int nxt = (t <= p[i] ? t + a[i] : max(0, t - b[i]));
            dp[i][t] = dp[i + 1][nxt];
        }
    }

    int q;
    cin >> q;
    while(q--){
        int x;
        cin >> x;
        auto it = lower_bound(sum_b.begin(), sum_b.end(), max(0, x - 1000));

        if(it == sum_b.end()){
            cout << x - sum_b.back() << endl;
        } else {
            int d = distance(sum_b.begin(), it);
            cout << dp[d][x - *it] << endl;
        }
    }
    
    return 0;
}