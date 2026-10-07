#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

int main(){
    
    int h, w, k;
    cin >> h >> w >> k;
    vector<string> s(h);
    rep(i,h) cin >> s[i];

    vector<bool> row(h, true), col(w, true);
    rep(i,h){
        rep(j,w){
            if(s[i][j] == '#'){
                row[i] = false;
                col[j] = false;
            }
        }
    }

    queue<pair<int,int>> que;
    vector<vector<int>> dist(h, vector<int>(w, -1));
    rep(i,h){
        rep(j,w){
            if(row[i] && col[j]){
                que.push({i, j});
                dist[i][j] = 0;
            }
        }
    }

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

    int ans = 0;
    rep(i,h) rep(j,w){
        if(dist[i][j] >= 0 && dist[i][j] <= k) ans++;
    }
    cout << ans << endl;
    
    return 0;
}