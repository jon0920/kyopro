#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n, m, k;
    cin >> n >> m >> k;
    vector<pair<int,ll>> cp(n);
    rep(i,n) cin >> cp[i].first >> cp[i].second;
    vector<vector<bool>> ng(n, vector<bool>(n));
    rep(i,m){
        int u, v;
        cin >> u >> v;
        u--, v--;
        ng[u][v] = true;
        ng[v][u] = true;
    }

    ll ans = 0;
    for(int bit = 0; bit < (1 << n); bit++){
        vector<int> vec;
        ll sum = 0;
        ll cost = 0;
        rep(i,n){
            if(1 & (bit >> i)){
                vec.push_back(i);
                cost += cp[i].first;
                sum += cp[i].second;
            }
        }
        int sz = vec.size();
        bool ok = true;
        rep(i,sz){
            for(int j = i + 1; j < sz; j++){
                if(ng[vec[i]][vec[j]]) ok = false;
            }
        }

        if(ok && cost <= k){
            ans = max(ans, sum);
        }
    }

    cout << ans << endl;

    return 0;
}