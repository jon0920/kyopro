#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

int main(){
    
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i,h) cin >> s[i];
    
    auto in_grid = [&](int x, int y){
        return (x >= 0 && x < h && y >= 0 && y < w);
    };

    rep(i,h) rep(j,w){
        if(s[i][j] == '#'){
            rep(d,4){
                int x = i + dx[d];
                int y = j + dy[d];
                if(!in_grid(x, y)) continue;
                if(s[x][y] == '.') s[x][y] = '!';
            }
        }
    }

    int ans = 1;
    vector<vector<int>> id(h, vector<int>(w, -1));
    int num = 0;
    rep(i,h) rep(j,w){
        if(s[i][j] == '.' && id[i][j] == -1){
            int cnt = 1;
            num++;
            id[i][j] = num;
            queue<pair<int,int>> que;
            que.push({i, j});
            while(!que.empty()){
                auto [x, y] = que.front(); que.pop();
                rep(d,4){
                    int nx = x + dx[d];
                    int ny = y + dy[d];
                    if(!in_grid(nx, ny)) continue;
                    if(id[nx][ny] == num) continue;

                    cnt++;
                    id[nx][ny] = num;
                    if(s[nx][ny] == '.') que.push({nx, ny});
                }
            }
            ans = max(ans, cnt);
        }
    }

    cout << ans << endl;
    
    return 0;
}