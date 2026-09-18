#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int h, w;
    cin >> h >> w;
    vector<vector<char>> c(h, vector<char>(w));
    rep(i,h) rep(j,w) cin >> c[i][j];

    queue<pair<int,int>> que;
    que.push({0,0});
    vector<vector<int>> dist(h, vector<int>(w, -1));
    dist[0][0] = 1;

    while(!que.empty()){
        auto [x, y] = que.front(); que.pop();
        if(y + 1 < w){
            if(dist[x][y + 1] == -1 && c[x][y + 1] == '.'){
                dist[x][y + 1] = dist[x][y] + 1;
                que.push({x, y + 1});
            }
        }
        if(x + 1 < h){
            if(dist[x + 1][y] == -1 && c[x + 1][y] == '.'){
                dist[x + 1][y] = dist[x][y] + 1;
                que.push({x + 1, y});
            }
        }
    }

    int ans = 0;
    rep(i,h) rep(j,w) ans = max(ans, dist[i][j]);
    cout << ans << endl;

    return 0;
}