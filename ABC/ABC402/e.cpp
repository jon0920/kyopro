#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

struct S{
    int s, c, p;
};

int main(){
    
    int n, x;
    cin >> n >> x;
    vector<S> cand(n);
    rep(i,n){
        cin >> cand[i].s >> cand[i].c >> cand[i].p;
    }

    vector<vector<double>> dp((1 << n), vector<double>(x + 1, 0));

    for(int rem = 0; rem <= x; rem++){
        for(int mask = 0; mask < (1 << n); mask++){
            rep(i,n){
                if((mask >> i) & 1) continue;
                if(rem < cand[i].c) continue;

                int next_mask = mask | (1 << i);
                int next_rem = rem - cand[i].c;

                double P = cand[i].p / 100.0;

                double val = P * (cand[i].s + dp[next_mask][next_rem]) + (1 - P) * (dp[mask][next_rem]);

                dp[mask][rem] = max(dp[mask][rem], val);
            }
        }
    }

    cout << fixed << setprecision(17);
    cout << dp[0][x] << endl;
    
    return 0;
}