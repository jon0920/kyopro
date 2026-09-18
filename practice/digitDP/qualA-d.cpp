#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

const ll INF = 1e18;

int main(){
    
    ll a;
    int k;
    cin >> a >> k;
    string A = to_string(a);
    int n = A.size();

    ll dp_min[20][2][2][1<<10];
    fill((ll*)dp_min, (ll*)dp_min + sizeof(dp_min) / sizeof(ll), INF);
    dp_min[0][0][0][0] = 0;

    rep(i,n){
        int a_dig = A[i] - '0';
        rep(gre,2){
            rep(is_started,2){
                rep(mask,(1 << 10)){
                    if(dp_min[i][gre][is_started][mask] == INF) continue;

                    rep(d,10){
                        if(gre == 0 && d < a_dig) continue;

                        int next_gre = gre | (d > a_dig);
                        int next_started = is_started | (d > 0);
                        int next_mask = mask;
                        if(next_started == 1){
                            next_mask |= (1 << d);
                        }

                        if(__builtin_popcount(next_mask) > k) continue;

                        ll next_val = dp_min[i][gre][is_started][mask] * 10 + d;

                        dp_min[i + 1][next_gre][next_started][next_mask] = min(dp_min[i + 1][next_gre][next_started][next_mask], next_val);
                    }
                }
            }
        }
    }

    ll dp_max[20][2][2][1<<10];
    fill((ll*)dp_max, (ll*)dp_max + sizeof(dp_max) / sizeof(ll), -INF);
    dp_max[0][0][0][0] = 0;

    rep(i,n){
        int a_dig = A[i] - '0';
        rep(smaller,2){
            rep(is_started,2){
                rep(mask,(1 << 10)){
                    if(dp_max[i][smaller][is_started][mask] == -INF) continue;

                    rep(d,10){
                        if(smaller == 0 && d > a_dig) continue;

                        int next_smaller = smaller | (d < a_dig);
                        int next_started = is_started | (d > 0);
                        int next_mask = mask;
                        if(next_started == 1){
                            next_mask |= (1 << d);
                        }

                        if(__builtin_popcount(next_mask) > k) continue;
                        
                        ll next_val = dp_max[i][smaller][is_started][mask] * 10 + d;
                        dp_max[i + 1][next_smaller][next_started][next_mask] = max(dp_max[i + 1][next_smaller][next_started][next_mask], next_val);
                    }
                }
            }
        }
    }

    ll ans = INF;
    rep(i,2){
        rep(j,2){
            rep(mask,(1 << 10)){
                if(__builtin_popcount(mask) > k) continue;
                if(dp_min[n][i][j][mask] != INF) ans = min(ans, dp_min[n][i][j][mask] - a);
                if(dp_max[n][i][j][mask] != -INF) ans = min(ans, a - dp_max[n][i][j][mask]);
            }
        }
    }

    cout << ans << endl;
    
    return 0;
}