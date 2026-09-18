#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
const int INF = 1e9;

int main(){
    
    int h, w, k;
    cin >> h >> w >> k;
    vector<string> s(h);
    vector<pair<int,int>> a(k + 2);
    int cnt = 1;
    rep(i,h){
        cin >> s[i];
        rep(j,w){
            if(s[i][j] == '@') a[0] = {i, j};
            if(s[i][j] == 'F'){
                a[cnt] = {i, j};
                cnt++;
            }
            if(s[i][j] == 'G') a[k + 1] = {i, j};
        }
    }

    vector<vector<int>> dist(k + 2, vector<int>(k + 2, -1));
    rep(i,k+2){
        auto [sx, sy] = a[i];
        vector<vector<int>> d(h, vector<int>(w, INF));
        d[sx][sy] = 0;
        queue<pair<int,int>> que;
        que.push({sx, sy});
        while(!que.empty()){
            auto [x, y] = que.front(); que.pop();
            rep(di,4){
                int nx = x + dx[di];
                int ny = y + dy[di];
                if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
                if(s[nx][ny] == '#') continue;
                if(d[nx][ny] != INF) continue;
                d[nx][ny] = d[x][y] + 1;
                que.push({nx, ny});
            }
        }
        rep(j,k+2){
            dist[i][j] = d[a[j].first][a[j].second];
        }
    }

    vector<vector<int>> dp((1 << (k + 2)), vector<int>(k + 2, INF));
    dp[1][0] = 0;
    for(int s = 0; s < (1 << (k + 2)); s++){
        rep(i,k+2){
            rep(j,k+2){
                int ss = s | (1 << j);
                if(s == ss) continue;
                dp[ss][j] = min(dp[ss][j], dp[s][i] + dist[i][j]);
            }
        }
    }
    
    int ans = dp[(1 << (k + 2)) - 1][k + 1];
    cout << (ans == INF ? -1 : ans) << endl;
    
    return 0;
}