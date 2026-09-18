#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, m;
    cin >> n >> m;
    vector<tuple<ll,ll,ll>> tws(m);
    rep(i,m){
        ll t, w, s;
        cin >> t >> w >> s;
        tws[i] = {t, w, s};
    }

    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
    set<int> standby;
    rep(i,n) standby.insert(i);
    vector<ll> ans(n);
    for(auto [t, w, s] : tws){
        while(!pq.empty() && pq.top().first <= t){
            standby.insert(pq.top().second);
            pq.pop();
        }

        if(!standby.empty()){
            int id = *standby.begin();
            ans[id] += w;
            pq.push({t + s, id});
            standby.erase(id);
        }
    }

    for(auto x : ans) cout << x << endl;
    
    return 0;
}