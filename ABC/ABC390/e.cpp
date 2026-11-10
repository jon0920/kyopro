#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, x;
    cin >> n >> x;
    vector<tuple<ll,ll,ll>> food(n);
    rep(i,n){
        ll v, a, c;
        cin >> v >> a >> c;
        food[i] = {v - 1, a, c};
    }

    auto DP = [&](int i){
        vector<ll> res(x + 1, -1);
        res[0] = 0;
        for(auto [v, a, c] : food){
            if(v != i) continue;
            vector<ll> nxt(x + 1, -1);
            rep(w,x + 1){
                if(res[w] == -1) continue;
                nxt[w] = max(nxt[w], res[w]);
                if(w + c <= x) nxt[w + c] = max(nxt[w + c], res[w] + a);
            }
            res = move(nxt);
        }
        ll mx = -1;
        rep(j,x + 1){
            mx = max(mx, res[j]);
            res[j] = mx;
        }
        return res;
    };
    
    vector<vector<ll>> dp(3, vector<ll>(x + 1));
    rep(i,3) dp[i] = DP(i);

    auto calc = [&](int i, ll val) -> ll {
        rep(j,x + 1){
            if(dp[i][j] >= val) return j;
        }
        return 1e18;
    };

    ll ok = 0, ng = 1e18;
    while(ng - ok > 1){
        ll mid = (ok + ng) / 2;
        ll sum = 0;
        rep(i,3){
            sum += calc(i, mid);
        }
        if(sum <= x) ok = mid;
        else ng = mid;
    }

    cout << ok << endl;
    
    return 0;
}