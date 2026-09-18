#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

const int INF = 1e9;
const string sn = "snuke";

const int dx[] = {0, -1, 0, 1};
const int dy[] = {1, 0, -1, 0};

int main() {

    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i,h) cin >> s[i];
    if(s[0][0] != 's'){
        cout << "No" << endl;
        return 0;
    }

    vector<vector<int>> dist(h, vector<int>(w, INF));
    dist[0][0] = 0;
    queue<pair<int,int>> que;
    que.push({0,0});

    while(!que.empty()){
        auto [x, y] = que.front(); que.pop();
        rep(d,4){
            int nx = x + dx[d];
            int ny = y + dy[d];
            if(nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
            if(dist[nx][ny] != INF) continue;
            if(sn[(dist[x][y] + 1) % 5] != s[nx][ny]) continue;

            dist[nx][ny] = dist[x][y] + 1;
            que.push({nx, ny});
        }
    }

    if(dist[h - 1][w - 1] != INF) cout << "Yes" << endl;
    else cout << "No" << endl;
    
    return 0;
}