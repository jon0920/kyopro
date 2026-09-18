#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int t;
    cin >> t;
    while(t--){
        int n, c;
        cin >> n >> c;
        vector<string> s(n);
        rep(i,n) cin >> s[i];
        vector<vector<bool>> wall(n, vector<bool>(n));
        rep(i,n){
            for(int j = n - 1; j >= 0; j--){
                if(j == n - 1){
                    if(s[j][i] == '#') wall[j][i] = false;
                    else wall[j][i] = true;
                }
                else{
                    if(s[j][i] != '#' && wall[j + 1][i]) wall[j][i] = true;
                    else wall[j][i] = false;
                }
            }
        }

        vector<vector<bool>> visited(n, vector<bool>(n, false));
        visited[n - 1][c - 1] = true;
        queue<pair<int,int>> que;
        que.push({n - 1, c - 1});
        while(!que.empty()){
            auto [x, y] = que.front(); que.pop();
            for(int i = -1; i <= 1; i++){
                int nx = x - 1;
                int ny = y + i;
                if(nx < 0 || ny < 0 || ny >= n) continue;
                if(visited[nx][ny]) continue;
                if(s[nx][ny] == '#' && !wall[nx + 1][ny]) continue;
                if(s[nx][ny] != '#'){
                    que.push({nx, ny});
                    if(wall[nx + 1][ny]) wall[nx][ny] = true;
                    visited[nx][ny] = true;
                    continue;
                }
                if(s[nx][ny] == '#' && wall[nx + 1][ny]){
                    que.push({nx, ny});
                    wall[nx][ny] = true;
                    visited[nx][ny] = true;
                }
            }
        }
        for(auto x : visited[0]){
            if(x) cout << 1;
            else cout << 0;
        }
        cout << endl;
    }

    return 0;
}