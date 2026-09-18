#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int bfs(int start, vector<vector<int>> &G){
    int n = G.size();
    vector<int> dist(n, -1);
    queue<int> q;

    dist[start] = 0;
    q.push(start);
    while(!q.empty()){
        int v = q.front(); q.pop();
        for(auto nv : G[v]){
            if(dist[nv] != -1) continue;
            dist[nv] = dist[v] + 1;
            q.push(nv);
        }
    }
    return *max_element(dist.begin(), dist.end());
}

int main() {
    
    int n1, n2, m;
    cin >> n1 >> n2 >> m;
    vector<vector<int>> G1(n1), G2(n2);
    rep(i,m){
        int a, b;
        cin >> a >> b;
        a--, b--;
        if(a < n1){
            G1[a].push_back(b);
            G1[b].push_back(a);
        }
        else{
            a -= n1; b -= n1;
            G2[a].push_back(b);
            G2[b].push_back(a);
        }
    }

    int ans = bfs(0, G1) + bfs(n2 - 1, G2) + 1;
    cout << ans << endl;
    
    return 0;
}