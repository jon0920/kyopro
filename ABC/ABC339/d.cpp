#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

struct S{
    int x1, y1, x2, y2;
};

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

int main(){
    
    int n;
    cin >> n;
    vector<string> s(n);
    rep(i,n) cin >> s[i];
    int p1x = -1, p1y = -1, p2x = -1, p2y = -1; 
    rep(i,n){
        rep(j,n){
            if(s[i][j] == 'P'){
                if(p1x == -1){
                    p1x = i; p1y = j;
                } else {
                    p2x = i; p2y = j;
                }
            }
        }
    }

    int dist[n][n][n][n];
    rep(i,n) rep(j,n) rep(k,n) rep(l,n) dist[i][j][k][l] = -1;
    dist[p1x][p1y][p2x][p2y] = 0;
    queue<S> que;
    que.push({p1x, p1y, p2x, p2y});

    while(!que.empty()){
        auto [x1, y1, x2, y2] = que.front(); que.pop();
        rep(d,4){
            int nx1 = x1 + dx[d];
            int ny1 = y1 + dy[d];
            int nx2 = x2 + dx[d];
            int ny2 = y2 + dy[d];
            if(nx1 < 0 || ny1 < 0 || nx1 >= n || ny1 >= n || s[nx1][ny1] == '#'){
                nx1 = x1; ny1 = y1;
            }
            if(nx2 < 0 || ny2 < 0 || nx2 >= n || ny2 >= n || s[nx2][ny2] == '#'){
                nx2 = x2; ny2 = y2;
            }
            if(dist[nx1][ny1][nx2][ny2] == -1){
                dist[nx1][ny1][nx2][ny2] = dist[x1][y1][x2][y2] + 1;
                que.push({nx1, ny1, nx2, ny2});
            }
        }
    }

    int ans = 1e9;
    rep(i,n) rep(j,n){
        if(dist[i][j][i][j] != -1) ans = min(ans, dist[i][j][i][j]);
    }

    cout << (ans == 1e9 ? -1 : ans) << endl;
      
    return 0;
}