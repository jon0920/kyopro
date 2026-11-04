#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    cin >> n;
    vector<string> s(n);
    rep(i,n) cin >> s[i];
    
    vector<vector<int>> ans(n, vector<int>(n, -1));
    queue<pair<int,int>> que;
    rep(i,n){
        que.push({i, i});
        ans[i][i] = 0;
    }

    rep(i,n){
        rep(j,n){
            if(ans[i][j] == -1 && s[i][j] != '-'){
                ans[i][j] = 1;
                que.push({i, j});
            }
        }
    }

    while(!que.empty()){
        auto [x, y] = que.front(); que.pop();
        rep(nx,n){
            rep(ny,n){
                if(ans[nx][ny] != -1) continue;
                if(s[nx][x] == '-' || s[y][ny] == '-') continue;
                if(s[nx][x] != s[y][ny]) continue;

                ans[nx][ny] = ans[x][y] + 2;
                que.push({nx, ny});
            }
        }
    }

    rep(i,n){
        rep(j,n){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}