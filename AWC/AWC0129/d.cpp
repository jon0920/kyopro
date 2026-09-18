#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

//構造体優先度付きキュー
struct S{
    int dist, x, y;
    bool operator>(const S& other) const{
        return dist > other.dist;
    }
};

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

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

    vector<vector<int>> dist(h, vector<int>(w, 1e9));
    dist[sx][sy] = 0;
    priority_queue<S, vector<S>, greater<S>> pq;
    pq.push({0, sx, sy});

    while(!pq.empty()){
        auto [d, x, y] = pq.top(); pq.pop();
        if(dist[x][y] != d) continue;
        rep(dir,4){
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
            if(dist[nx][ny] <= dist[x][y]) continue;
            if(s[nx][ny] == 'B') continue;
            dist[nx][ny] = dist[x][y] + (s[nx][ny] == 'P');
            pq.push({dist[nx][ny], nx, ny});
        }
    }

    cout << (dist[gx][gy] == 1e9 ? -1 : dist[gx][gy]) << endl;
    
    return 0;
}