#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

const int INF = 1e9;
const int dx[] = {0, 0, -1, -1, -1, 1, 1, 1};
const int dy[] = {-1, 1, 0, -1, 1, 0, -1, 1};

struct S{
    int d; int x; int y;
};

int main(){
    
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i,h) cin >> s[i];

    vector<vector<int>> dist(h, vector<int>(w, INF));
    queue<pair<int,int>> que;
    bool has_black = false;
    bool has_white = false;
    rep(i,h) rep(j,w){
        if(s[i][j] == '#'){
            has_black = true;
            bool ok = false;
            rep(dir,8){
                int nx = i + dx[dir];
                int ny = j + dy[dir];
                if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
                if(s[nx][ny] == '.') ok = true;
            }
            if(ok){
                que.push({i, j});
                dist[i][j] = 0;
            } else {
            }
        } else has_white = true;
    }

    if(!has_black || !has_white){
        rep(i,h){
            rep(j,w) cout << '.';
            cout << endl;
        }
        return 0;
    }

    while(!que.empty()){
        auto [x, y] = que.front(); que.pop();
        rep(dir,8){
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
            if(dist[nx][ny] != INF) continue;
            dist[nx][ny] = dist[x][y] + 1;
            que.push({nx, ny});
        }
    }

    rep(i,h){
        rep(j,w){
            if(dist[i][j] % 2 == 0) cout << '#';
            else cout << '.';
        }
        cout << endl;
    }

    
    return 0;
}