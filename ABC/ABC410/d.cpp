#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

const int mx = 1024;

int main(){

    int n, m;
    cin >> n >> m;
    vector<vector<pair<int,int>>> G(n + 1);
    rep(i,m){
        int a, b, w;
        cin >> a >> b >> w;
        G[a].push_back({b, w});
    }

    vector<vector<bool>> visited(n + 1, vector<bool>(mx));
    visited[1][0] = true;
    queue<pair<int,int>> que;
    que.push({1, 0});

    while(!que.empty()){
        auto [v, sw] = que.front(); que.pop();
        for(auto [nv, w] : G[v]){
            int nw = w ^ sw;
            if(!visited[nv][nw]){
                visited[nv][nw] = true;
                que.push({nv, nw});
            }
        }
    }

    int ans = -1;
    rep(i,mx){
        if(visited[n][i]){
            ans = i;
            break;
        }
    }
    cout << ans << endl;

    return 0;
}