#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, m;
    cin >> n >> m;
    set<pair<int,int>> can_move;
    rep(i,n) rep(j,n){
        if(i * i + j * j == m){
            can_move.insert({i, j});
            can_move.insert({-i, j});
            can_move.insert({i, -j});
            can_move.insert({-i, -j});
        }
    }

    vector<vector<int>> dist(n, vector<int>(n, -1));
    dist[0][0] = 0;
    queue<pair<int,int>> que;
    que.push({0, 0});
    while(!que.empty()){
        auto [x, y] = que.front(); que.pop();
        for(auto [dx, dy] : can_move){
            int nx = x + dx;
            int ny = y + dy;
            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if(dist[nx][ny] != -1) continue;
            dist[nx][ny] = dist[x][y] + 1;
            que.push({nx, ny});
        }
    }

    rep(i,n){
        rep(j,n) cout << dist[i][j] << " ";
        cout << endl;
    }
    
    return 0;
}