#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

const int dx[] = {1, 1, 0, -1, -1, 0};
const int dy[] = {0, 1, 1, 0, -1, -1};

int main() {
    
    int n;
    cin >> n;
    vector<vector<int>> grid(2100, vector<int>(2100, 0));
    vector<int> x(n + 1), y(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> x[i] >> y[i];
        x[i] += 1000; y[i] += 1000;
        grid[x[i]][y[i]] = i;
    }

    dsu uf(n + 1);
    for(int i = 1; i <= n; i++){
        rep(d,6){
            int nx = x[i] + dx[d];
            int ny = y[i] + dy[d];
            if(grid[nx][ny] > 0){
                uf.merge(i, grid[nx][ny]);
            }
        }
    }

    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(uf.leader(i) == i) ans++;
    }
    cout << ans << endl;
    
    
    return 0;
}