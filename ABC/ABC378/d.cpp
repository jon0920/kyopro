#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

const int dx[] = {0, -1, 0, 1};
const int dy[] = {1, 0, -1, 0};

int h, w, k;
vector<string> s;
vector<vector<bool>> used;
ll ans = 0;

void dfs(int x, int y, int lv){
    if(lv == k){
        ans++;
        return;
    }
    used[x][y] = true;
    rep(i,4){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
        if(s[nx][ny] != '.') continue;
        if(used[nx][ny]) continue;

        dfs(nx, ny, lv + 1);
    }
    used[x][y] = false;
}

int main() {
    
    cin >> h >> w >> k;
    s.resize(h);
    rep(i,h) cin >> s[i];
    used.resize(h, vector<bool>(w));
    
    rep(i,h) rep(j,w){
        if(s[i][j] == '.') dfs(i, j, 0);
    }
    cout << ans << endl;
    
    return 0;
}