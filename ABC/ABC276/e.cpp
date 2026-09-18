#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

int main(){

    int h, w;
    cin >> h >> w;
    vector<vector<char>> c(h, vector<char>(w));
    int sx, sy;
    rep(i,h) rep(j,w){
        cin >> c[i][j];
        if(c[i][j] == 'S') sx = i, sy = j;
    }

    auto in_grid = [&](int x, int y) -> bool {
        return (x >= 0 && x < h && y >= 0 && y < w);
    };

    vector<vector<int>> dist(h, vector<int>(w, -1));
    queue<pair<int,int>> que;
    rep(d,4){
        int nx = sx + dx[d];
        int ny = sy + dy[d];
        if(!in_grid(nx, ny)) continue;
        if(c[nx][ny] == '.'){
            que.push({nx, ny});
            dist[nx][ny] = d;
        }
    }

    while(!que.empty()){
        auto [x, y] = que.front(); que.pop();
        rep(d,4){
            int nx = x + dx[d];
            int ny = y + dy[d];
            if(!in_grid(nx, ny)) continue;
            if(c[nx][ny] == '#') continue;
            if(nx == sx && ny == sy) continue;

            if(dist[nx][ny] != -1){
                if(dist[nx][ny] != dist[x][y]){
                    cout << "Yes" << endl;
                    return 0;
                }
                continue;
            }
            dist[nx][ny] = dist[x][y];
            que.push({nx, ny});
        }
    }

    cout << "No" << endl;

    return 0;
}