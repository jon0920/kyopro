#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

struct S{
  int D, x, y;  
};

int main(){
    
    int h, w;
    cin >> h >> w;
    vector<string> c(h);
    rep(i,h) cin >> c[i];
    int sx, sy, gx, gy;
    rep(i,h) rep(j,w){
        if(c[i][j] == 'S'){
            sx = i; sy = j;
        }
        if(c[i][j] == 'G'){
            gx = i; gy = j;
        }
    }

    vector<vector<int>> dist(h, vector<int>(w, 1e9));
    dist[sx][sy] = 0;
    auto f = [](S a, S b){
        return a.D > b.D;
    };
    priority_queue<S, vector<S>, decltype(f)> pq(f); 
    pq.push({0, sx, sy});

    while(!pq.empty()){
        auto [D, x, y] = pq.top(); pq.pop();
        if(dist[x][y] != D) continue;
        rep(d,4){
            int nx = x + dx[d];
            int ny = y + dy[d];
            if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
            if(c[nx][ny] == 'X') continue;

            if(c[x][y] == 'V'){
                if(c[nx][ny] == 'V'){
                    if(dist[nx][ny] > D){
                        dist[nx][ny] = D;
                        pq.push({dist[nx][ny], nx, ny});
                    }
                } else {
                    if(dist[nx][ny] > D + 1){
                        dist[nx][ny] = D + 1;
                        pq.push({dist[nx][ny], nx, ny});
                    }
                }
            } else {
                if(c[nx][ny] == 'V'){
                    if(dist[nx][ny] > D + 2){
                        dist[nx][ny] = D + 2;
                        pq.push({dist[nx][ny], nx, ny});
                    }
                } else {
                    if(dist[nx][ny] > D + 1){
                        dist[nx][ny] = D + 1;
                        pq.push({dist[nx][ny], nx, ny});
                    }
                } 
            }
        }
    }

    if(dist[gx][gy] == 1e9) cout << "NO" << endl;
    else cout << dist[gx][gy] << endl;
    
    return 0;
}