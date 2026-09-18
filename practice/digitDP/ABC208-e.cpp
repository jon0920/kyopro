#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    string N;
    ll k;
    cin >> N >> k;
    int n = N.size();

    map<ll,ll> dp[2][2];
    dp[0][0][1] = 1;

    rep(i,n){
        map<ll,ll> ndp[2][2];
        rep(smaller,2){
            rep(started,2){
                for(auto [prod, cnt] : dp[smaller][started]){
                    int lim = smaller ? 9 : N[i] - '0';
                    rep(d,lim + 1){
                        int next_smaller = smaller | (d < lim);
                        int next_started = started | (d != 0);
                        ll next_prod = prod;
                        if(next_started){
                            if(!started) next_prod = d;
                            else {
                                if(d == 0) next_prod = 0;
                                else if(prod * d > k) next_prod = k + 1;
                                else next_prod = prod * d;
                            }
                        }
                        ndp[next_smaller][next_started][next_prod] += cnt;
                    }
                }
            }
        }
        swap(dp,ndp);
    }

    ll ans = 0;
    rep(smaller,2){
        for(auto [prod, cnt] : dp[smaller][1]){
            if(prod <= k) ans += cnt;
        }
    }

    cout << ans << endl;
    
    return 0;
}