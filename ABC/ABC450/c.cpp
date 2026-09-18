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

    int ans = 0;
    vector<vector<bool>> seen(h, vector<bool>(w));
    rep(i,h) rep(j,w){
        if(s[i][j] == '.' && !seen[i][j]){
            bool ok = true;
            seen[i][j] = true;
            queue<pair<int,int>> que;
            que.push({i, j});
            while(!que.empty()){
                auto [x, y] = que.front(); que.pop();
                if(x == 0 || y == 0 || x == h - 1 || y == w - 1) ok = false;
                rep(d,4){
                    int nx = x + dx[d];
                    int ny = y + dy[d];
                    if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
                    if(seen[nx][ny]) continue;
                    if(s[nx][ny] == '#') continue;
                    seen[nx][ny] = true;
                    que.push({nx, ny});
                }
            }
            if(ok) ans++;
        }
    }

    cout << ans << endl;
    
    return 0;
}