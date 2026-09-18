#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    vector<vector<int>> a(3, vector<int>(3));
    rep(i,3) rep(j,3) cin >> a[i][j];
    vector<vector<int>> grid(3, vector<int>(3));

    auto check = [&](vector<vector<int>> &grid, int t){
        rep(i,3){
            if(grid[i][0] == t && grid[i][1] == t && grid[i][2] == t) return true;
            if(grid[0][i] == t && grid[1][i] == t && grid[2][i] == t) return true;
        }
        if(grid[0][0] == t && grid[1][1] == t && grid[2][2] == t) return true;
        if(grid[0][2] == t && grid[1][1] == t && grid[2][0] == t) return true;

        return false;
    };

    auto solve = [&](auto solve, vector<vector<int>> &grid, int turn, ll t_score, ll a_score, int cnt) -> int {
        if(turn == 1 && check(grid, 2)) return 2;
        if(turn == 2 && check(grid, 1)) return 1;
        if(cnt == 9){
            if(t_score > a_score) return 1;
            return 2;
        }
        
        if(turn == 1){
            rep(i,3){
                rep(j,3){
                    if(grid[i][j] == 0){
                        grid[i][j] = 1;
                        int res = solve(solve, grid, 2, t_score + a[i][j], a_score, cnt + 1);
                        grid[i][j] = 0;
                        if(res == 1) return 1;
                    }
                }
            }
            return 2;
        } else {
            rep(i,3){
                rep(j,3){
                    if(grid[i][j] == 0){
                        grid[i][j] = 2;
                        int res = solve(solve, grid, 1, t_score, a_score + a[i][j], cnt + 1);
                        grid[i][j] = 0;
                        if(res == 2) return 2;
                    }
                }
            }
            return 1;
        }
    };

    int ans = solve(solve, grid, 1, 0, 0, 0);

    if(ans == 1) cout << "Takahashi" << endl;
    else cout << "Aoki" << endl;

    return 0;
}