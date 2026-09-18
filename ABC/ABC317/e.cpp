#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

int main(){
    
    int h, w;
    cin >> h >> w;
    vector<string> a(h);
    rep(i,h) cin >> a[i];

    int sx, sy, gx, gy;
    rep(i,h){
        rep(j,w){
            if(a[i][j] == 'S'){
                sx = i; sy = j;
            } else if(a[i][j] == 'G'){
                gx = i; gy = j;
                a[i][j] = '.';
            } else if(a[i][j] == '^'){
                for(int x = i - 1; x >= 0; x--){
                    if(a[x][j] != '.' && a[x][j] != '!') break;
                    a[x][j] = '!';
                }
            } else if(a[i][j] == '>'){
                for(int y = j + 1; y < w; y++){
                    if(a[i][y] != '.' && a[i][y] != '!') break;
                    a[i][y] = '!';
                }
            } else if(a[i][j] == 'v'){
                for(int x = i + 1; x < h; x++){
                    if(a[x][j] != '.' && a[x][j] != '!') break;
                    a[x][j] = '!';
                }      
            } else if(a[i][j] == '<'){
                for(int y = j - 1; y >= 0; y--){
                    if(a[i][y] != '.' && a[i][y] != '!') break;
                    a[i][y] = '!';
                }
            }
        }
    }

    vector<vector<int>> dist(h, vector<int>(w, -1));
    dist[sx][sy] = 0;
    queue<pair<int,int>> que;
    que.push({sx, sy});

    while(!que.empty()){
        auto [x, y] = que.front(); que.pop();
        rep(d,4){
            int nx = x + dx[d];
            int ny = y + dy[d];
            if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
            if(a[nx][ny] != '.') continue;
            if(dist[nx][ny] != -1) continue;

            dist[nx][ny] = dist[x][y] + 1;
            que.push({nx, ny});
        }
    }

    cout << dist[gx][gy] << endl;
    
    return 0;
}