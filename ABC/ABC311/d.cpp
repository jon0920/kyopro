#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

struct S{
    int x; int y; int dir;
};

int main(){

    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    rep(i,n) cin >> s[i];

    vector<vector<bool>> visited(n, vector<bool>(m));
    visited[1][1] = true;
    queue<S> que;
    if(s[1][2] == '.'){
        que.push({1, 2, 1});
    }
    if(s[2][1] == '.'){
        que.push({2, 1, 2});
    }

    while(!que.empty()){
        auto [x, y, d] = que.front(); que.pop();
        while(s[x + dx[d]][y + dy[d]] == '.'){
            visited[x][y] = true;
            x += dx[d];
            y += dy[d];
        }

        if(!visited[x][y]){
            visited[x][y] = true;
            rep(i,4){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(s[nx][ny] == '.'){
                    que.push({nx, ny, i});
                }
            }
        }
    }

    int ans = 0;
    rep(i,n) rep(j,m) if(visited[i][j]) ans++;
    cout << ans << endl;

    return 0;
}