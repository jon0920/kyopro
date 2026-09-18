#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n;
    cin >> n;
    map<ll,vector<pair<ll,ll>>> mp;
    rep(i,n){
        ll a, b;
        cin >> a >> b;
        a--, b--;
        mp[a].push_back({b,i});
        mp[b].push_back({a,i});
    }

    ll ans = 0;
    vector<bool> used(n, false);
    queue<ll> que;
    que.push(0);
    while(!que.empty()){
        ll v = que.front(); que.pop();
        if(mp.count(v)){
            for(auto [x, i] : mp[v]){
                if(used[i]) continue;
                que.push(x);
                used[i] = true;
                ans = max(ans, x);
            }
        }
    }
    cout << ans + 1 << endl;

    return 0;
}