#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];

    vector<vector<ll>> dp(45, vector<ll>(2, -1));
    dp[0][0] = 0;

    rep(i,40){
        int d = 39 - i;
        int k_bit = (k >> d) & 1;

        ll cnt0 = 0, cnt1 = 0;
        for(ll x : a){
            if((x >> d) & 1) cnt1++;
            else cnt0++;
        }

        ll score0 = cnt1 * (1LL << d);
        ll score1 = cnt0 * (1LL << d);

        rep(smaller,2){
            if(dp[i][smaller] == -1) continue;
            rep(bit,2){
                if(smaller == 0 && bit > k_bit) continue;

                int next_smaller = smaller;
                if(bit < k_bit) next_smaller = 1;

                ll cur_score = (bit == 0) ? score0 : score1;
                dp[i + 1][next_smaller] = max(dp[i + 1][next_smaller], dp[i][smaller] + cur_score);
            }
        }
    }

    cout << max(dp[40][0], dp[40][1]) << endl;
    
    return 0;
}