#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

using P = pair<int,int>; 
using TP = tuple<int,int,int,int>;
const int INF = 1e9;
const int MOD = 998244353;

int main(){
    
    int n, m;
    cin >> n >> m;
    vector<vector<P>> G(n);
    rep(i,m){
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        G[a].push_back({b, c});
    }

    vector<int> ans(n, -1);
    ans[0] = 0;

    priority_queue<TP, vector<TP>, greater<TP>> pq;
    for(auto [b, c] : G[0]) pq.push({0, c, b, c});

    int rank = 0;
    P last = {INF, INF};
    while(!pq.empty()){
        auto [r, c, v, x] = pq.top(); pq.pop();
        if(ans[v] != -1) continue;

        if(last != make_pair(r, c)){
            rank++;
            last = {r, c};
        }

        ans[v] = x;
        for(auto [nv, nc] : G[v]){
            if(ans[nv] == -1){
                int nx = (10LL * x + nc) % MOD;
                pq.push({rank, nc, nv, nx});
            }
        }
    }

    for(int i = 1; i < n; i++) cout << ans[i] << endl;
    
    return 0;
}