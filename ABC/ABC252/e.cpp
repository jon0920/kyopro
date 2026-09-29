#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

using P = pair<ll,int>;
struct S{
    int to; ll cost; int id;
};
const ll INF = 1e18;

int main(){
    
    int n, m;
    cin >> n >> m;
    vector<vector<S>> G(n);
    rep(i,m){
        int a, b;
        ll c;
        cin >> a >> b >> c;
        a--, b--;
        G[a].push_back({b, c, i});
        G[b].push_back({a, c, i});
    }

    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push({0, 0});
    vector<P> dist(n, {INF, -1});
    dist[0] = {0, -1};

    while(!pq.empty()){
        auto [cost, v] = pq.top(); pq.pop();
        if(dist[v].first != cost) continue;
        for(auto [nv, nc, id] : G[v]){
            if(dist[nv].first <= dist[v].first + nc) continue;
            dist[nv].first = dist[v].first + nc;
            dist[nv].second = id;
            pq.push({dist[nv].first, nv});
        }
    }

    set<int> st;
    for(int i = 1; i < n; i++) st.insert(dist[i].second + 1);
    
    for(int x : st) cout << x << " ";
    cout << endl;
    
    return 0;
}