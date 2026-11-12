#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int main(){
    
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i,h) cin >> s[i];

    vector<vector<int>> dist(h, vector<int>(w, -1));
    dist[0][0] = 0;
    queue<pair<int,int>> que;
    que.push({0, 0});

    while(!que.empty()){
        auto [x, y] = que.front(); que.pop();
        rep(d,4){
            int nx = x + dx[d];
            int ny = y + dy[d];
            if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
            if(s[nx][ny] == '#') continue;
            if(dist[nx][ny] != -1) continue;

            dist[nx][ny] = dist[x][y] + 1;
            que.push({nx, ny});
        }
    }
    
    if(dist[h - 1][w - 1] == -1){
        cout << -1 << endl;
        return 0;
    }

    vector<vector<bool>> path(h, vector<bool>(w, false));
    path[h - 1][w - 1] = true;
    int cur_x = h - 1, cur_y = w - 1;
    while(dist[cur_x][cur_y] > 0){
        rep(d,4){
            int nx = cur_x + dx[d];
            int ny = cur_y + dy[d];
            if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;

            if(dist[nx][ny] == dist[cur_x][cur_y] - 1){
                path[nx][ny] = true;
                cur_x = nx;
                cur_y = ny;
                break;
            }
        }
    }

    int ans = 0;
    rep(i,h) rep(j,w){
        if(s[i][j] == '.' && !path[i][j]) ans++;
    }
    cout << ans << endl;
    
    return 0;
}