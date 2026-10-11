#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int m, a, b;
    cin >> m >> a >> b;
    vector<vector<int>> G(m, vector<int>(m, -1));

    for(int i = 1; i < m; i++){
        for(int j = 1; j < m; j++){
            if(G[i][j] == -1){
                pair<int,int> cur = {i, j};
                vector<pair<int,int>> cand;
                while(1){
                    cand.push_back(cur);
                    auto [x, y] = cur;
                    if(G[x][y] == 0){
                        for(auto [r, c] : cand){
                            G[r][c] = 0;
                        }
                        break;
                    }
                    if(G[x][y] != -1) break;
                    int z = (a * y + b * x) % m;
                    if(z == 0){
                        for(auto [r, c] : cand){
                            G[r][c] = 0;
                        }
                        break;
                    } else {
                        G[x][y] = z;
                        cur = {y, z};
                    }
                }
            }
        }
    }

    int ans = 0;
    for(int i = 1; i < m; i++){
        for(int j = 1; j < m; j++) if(G[i][j] != 0) ans++;
    }
    cout << ans << endl;
    
    return 0;
}