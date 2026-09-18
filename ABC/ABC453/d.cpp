#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
const char dir[] = {'U', 'D', 'L', 'R'};

const int INF = 1e9;

struct S{
    int x; int y; int d;
};

int main(){

    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i,h) cin >> s[i];

    int sx, sy, gx, gy;
    rep(i,h) rep(j,w){
        if(s[i][j] == 'S') sx = i, sy = j;
        if(s[i][j] == 'G') gx = i, gy = j;
    }

    vector<vector<vector<bool>>> visited(h, vector<vector<bool>>(w, vector<bool>(4, false)));
    S pre[h][w][4];
    S goal = {-1, -1, -1};
    queue<S> que;
    rep(i,4){
        int nx = sx + dx[i];
        int ny = sy + dy[i];
        if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
        if(s[nx][ny] == '#') continue;
        visited[nx][ny][i] = true;
        pre[nx][ny][i] = {-1, -1, -1};
        que.push({nx, ny, i});
    }

    while(!que.empty()){
        S crr = que.front(); que.pop();
        auto [x, y, d] = crr;
        if(x == gx && y == gy){
            goal = crr;
            break;
        }
        
        rep(i,4){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
            if(s[nx][ny] == '#') continue;
            if(s[x][y] == 'o' && d != i) continue;
            if(s[x][y] == 'x' && d == i) continue;
            if(visited[nx][ny][i]) continue;
            
            visited[nx][ny][i] = true;
            pre[nx][ny][i] = crr;
            que.push({nx, ny, i});
        }
    }

    if(goal.x == -1){
        cout << "No" << endl;
    } else {
        S crr = goal;
        string res = "";
        while(crr.x != -1){
            res += dir[crr.d];
            crr = pre[crr.x][crr.y][crr.d];
        }
        reverse(res.begin(), res.end());
        cout << "Yes" << endl;
        cout << res << endl;
    }

    return 0;
}