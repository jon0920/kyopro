#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

const int dx[] = {0, -1, -1, -1, 0, 1, 1, 1};
const int dy[] = {1, 1, 0, -1, -1, -1, 0, 1};

int main() {
    
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i,h) cin >> s[i];
    
    vector<vector<bool>> seen(h, vector<bool>(w));

    auto dfs = [&](auto dfs, int x, int y) -> void {
        seen[x][y] = true;
        rep(d,8){
            int nx = x + dx[d];
            int ny = y + dy[d];
            if(nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
            if(seen[nx][ny]) continue;
            if(s[nx][ny] == '#') dfs(dfs, nx, ny);
        }
    };

    int ans = 0;
    rep(i,h) rep(j,w){
        if(s[i][j] == '#' && !seen[i][j]){
            ans++;
            dfs(dfs, i, j);
        }
    }
    cout << ans << endl;
    
    return 0;
}