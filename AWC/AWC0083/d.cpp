#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

int main(){
    
    int h, w;
    cin >> h >> w;
    vector<vector<int>> G(h, vector<int>(w, 0));
    int n;
    cin >> n;
    rep(i,n){
        int r, c;
        cin >> r >> c;
        r--, c--;
        G[r][c] = 1;
    }

    vector<vector<int>> dist(h, vector<int>(w, -1));
    dist[0][0] = 0;
    queue<pair<int,int>> que;
    que.push({0, 0});
    while(!que.empty()){
        auto [x, y] = que.front(); que.pop();
        rep(dir,4){
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            while(1){
                if(nx < 0 || nx >= h || ny < 0 || ny >= w) break;
                if(G[nx][ny] == 1) break;
                nx += dx[dir];
                ny += dy[dir];
            }
            nx -= dx[dir];
            ny -= dy[dir];
            if(dist[nx][ny] == -1){
                dist[nx][ny] = dist[x][y] + 1;
                que.push({nx, ny});
            }
        }
    }

    cout << dist[h - 1][w - 1] << endl;
    
    return 0;
}