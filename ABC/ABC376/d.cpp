#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;


int main() {

    int n, m;
    cin >> n >> m;
    vector<vector<int>> G(n);
    rep(i,m){
        int a, b;
        cin >> a >> b;
        a--, b--;
        G[a].push_back(b);
    }

    vector<int> dist(n, -1);
    dist[0] = 0;
    queue<int> que;
    que.push(0);
    while(!que.empty()){
        int v = que.front(); que.pop();
        for(auto nv : G[v]){
            if(nv == 0){
                cout << dist[v] + 1 << endl;
                return 0;
            }
            if(dist[nv] == -1){
                dist[nv] = dist[v] + 1;
                que.push(nv);
            }
        }
    }
    cout << -1 << endl;
    
    return 0;
}