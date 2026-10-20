#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

const ll INF = 1e18;

int main(){
    
    int n, m, l;
    cin >> n >> m >> l;
    vector<int> a(n);
    vector<vector<int>> group(l);
    rep(i,n){
        cin >> a[i];
        group[i % l].push_back(a[i]);
    }

    vector<vector<ll>> cost(l, vector<ll>(m));
    rep(i,l){
        rep(r,m){
            ll res = 0;
            for(int x : group[i]){
                res += (r - x + m) % m;
            }
            cost[i][r] = res;
        }
    }

    vector<ll> dp(m, INF);
    dp[0] = 0;
    rep(i,l){
        vector<ll> ndp(m, INF);
        rep(cur,m){
            rep(nxt,m){
                ndp[(cur + nxt) % m] = min(ndp[(cur + nxt) % m], dp[cur] + cost[i][nxt]);
            }
        }
        dp = move(ndp);
    }

    cout << dp[0] << endl;
    
    return 0;
}