#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
const int INF = 1e9;

struct S
{
    int x; int y; int cond;
};


int main(){

    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i,h) cin >> s[i];
    int sx, sy, gx, gy;
    rep(i,h) rep(j,w){
        if(s[i][j] == 'S') sx = i, sy = j;
        if(s[i][j] == 'G') gx = i, gy = j;
    }

    vector<vector<vector<int>>> dist(h, vector<vector<int>>(w, vector<int>(2, INF)));
    queue<S> que;
    dist[sx][sy][0] = 0, dist[sx][sy][1] = 0;
    que.push({sx, sy, 0}); que.push({sx, sy, 1});

    while(!que.empty()){
        S crr = que.front(); que.pop();
        auto [x, y, c] = crr;
        if(c == 0){
            rep(d,2){
                int nx = x + dx[d];
                int ny = y + dy[d];
                if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
                if(s[nx][ny] == '#') continue;
                if(dist[nx][ny][1] != INF) continue;

                dist[nx][ny][1] = dist[x][y][c] + 1;
                que.push({nx, ny, 1});
            }
        } else {
            for(int d = 2; d < 4; d++){
                int nx = x + dx[d];
                int ny = y + dy[d];
                if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
                if(s[nx][ny] == '#') continue;
                if(dist[nx][ny][0] != INF) continue;
                
                dist[nx][ny][0] = dist[x][y][c] + 1;
                que.push({nx, ny, 0});
            }
        }
    }

    int ans = min(dist[gx][gy][0], dist[gx][gy][1]);
    cout << (ans != INF ? ans : -1) << endl;

    return 0;
}