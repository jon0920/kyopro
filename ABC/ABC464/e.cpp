#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

const int dx[] = {-1, 0};
const int dy[] = {0, -1};

int main(){
    
    int h, w, q;
    cin >> h >> w >> q;

    vector<tuple<int,int,char>> rcx(q);
    rep(i,q){
        int r, c;
        char x;
        cin >> r >> c >> x;
        r--, c--;
        rcx[i] = {r, c, x};
    }

    vector<vector<int>> grid(h, vector<int>(w, -1));
    for(int i = q - 1; i >= 0; i--){
        auto [r, c, s] = rcx[i];
        if(grid[r][c] != -1) continue;
        queue<pair<int,int>> que;
        que.push({r, c});
        grid[r][c] = i;
        while(!que.empty()){
            auto [x, y] = que.front(); que.pop();
            rep(d,2){
                int nx = x + dx[d];
                int ny = y + dy[d];
                if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
                if(grid[nx][ny] != -1) continue;

                grid[nx][ny] = i;
                que.push({nx, ny});
            }
        }
    }

    rep(i,h){
        rep(j,w){
            if(grid[i][j] == -1) cout << 'A';
            else{
                auto [x,y,c] = rcx[grid[i][j]];
                cout << c;
            }
        }
        cout << endl;
    }
    
    return 0;
}