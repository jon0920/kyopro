#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

const int INF = 1e9;
const int dx[] = {0, -1, 0, 1};
const int dy[] = {1, 0, -1, 0};

int main() {
    
    int h, w, D;
    cin >> h >> w >> D;
    vector<string> s(h);
    rep(i,h) cin >> s[i];

    queue<pair<int,int>> que;
    vector<vector<int>> dist(h, vector<int>(w, INF));
    rep(i,h) rep(j,w){
        if(s[i][j] == 'H'){
            dist[i][j] = 0;
            que.push({i, j});
        }
    }

    while(!que.empty()){
        auto [x, y] = que.front(); que.pop();
        rep(d,4){
            int nx = x + dx[d];
            int ny = y + dy[d];
            if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
            if(s[nx][ny] != '.') continue;
            if(dist[nx][ny] != INF) continue;
            dist[nx][ny] = dist[x][y] + 1;
            if(dist[nx][ny] < D) que.push({nx,ny});
        }
    }

    int ans = 0;
    rep(i,h) rep(j,w){
        if(dist[i][j] <= D) ans++;
    }
    
    cout << ans << endl;
    
    return 0;
}