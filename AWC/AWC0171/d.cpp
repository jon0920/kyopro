#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

const vector<pair<int,int>> ver = {{-1, 0}, {1, 0}};
const vector<pair<int,int>> hor = {{0, -1}, {0, 1}};

const int INF = 1e9;

int main(){
    
    int h, w;
    cin >> h >> w;
    vector<vector<int>> a(h, vector<int>(w));
    rep(i,h) rep(j,w) cin >> a[i][j];

    vector<vector<vector<int>>> dist(h, vector<vector<int>>(w, vector<int>(2, INF)));
    dist[0][0][0] = 0; dist[0][0][1] = 0;
    queue<tuple<int,int,int>> que;
    que.push({0, 0, 0});
    que.push({0, 0, 1});

    auto in_grid = [&](int x, int y){
        return x >= 0 && x < h && y >= 0 && y < w;
    };
    
    while(!que.empty()){
        auto [x, y, d] = que.front(); que.pop();
        if(d == 0){
            for(auto [dx, dy] : ver){
                int nx = x + dx;
                int ny = y + dy;
                if(!in_grid(nx, ny)) continue;
                if(a[nx][ny] == 1) continue;
                if(dist[nx][ny][1] != INF) continue;
                dist[nx][ny][1] = dist[x][y][d] + 1;
                que.push({nx, ny, 1}); 
            }
        } else {
            for(auto [dx, dy] : hor){
                int nx = x + dx;
                int ny = y + dy;
                if(!in_grid(nx, ny)) continue;
                if(a[nx][ny] == 1) continue;
                if(dist[nx][ny][0] != INF) continue;
                dist[nx][ny][0] = dist[x][y][1] + 1;
                que.push({nx, ny, 0});
            }
        }
    }

    int ans = min(dist[h - 1][w - 1][0], dist[h - 1][w - 1][1]);
    if(ans == INF) cout << "NONE" << endl;
    else cout << ans << endl;
    
    return 0;
}