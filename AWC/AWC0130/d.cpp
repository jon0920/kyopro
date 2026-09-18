#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

//2次元imos
int main(){
    
    int h, w, n;
    cin >> h >> w >> n;
    vector<vector<int>> imos(h + 1, vector<int>(w + 1));
    rep(i,n){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a--, c--;
        imos[a][c]++;
        imos[a][d]--;
        imos[b][c]--;
        imos[b][d]++;
    }

    rep(i,h){
        rep(j,w) imos[i][j + 1] += imos[i][j];
    }
    rep(i,w){
        rep(j,h) imos[j + 1][i] += imos[j][i];
    }

    vector<vector<int>> grid(h, vector<int>(w));
    rep(i,h) rep(j,w){
        grid[i][j] = (imos[i][j] % 2 == 1);
    }

    vector<vector<int>> idx(h, vector<int>(w, -1));
    int cnt = 0;
    rep(i,h){
        rep(j,w){
            if(grid[i][j] == 1 && idx[i][j] == -1){
                queue<pair<int,int>> que;
                que.push({i, j});
                idx[i][j] = cnt;
                while(!que.empty()){
                    auto [x, y] = que.front(); que.pop();
                    rep(d,4){
                        int nx = x + dx[d];
                        int ny = y + dy[d];
                        if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
                        if(grid[nx][ny] == 0) continue;
                        if(idx[nx][ny] != -1) continue;
                        idx[nx][ny] = cnt;
                        que.push({nx, ny});
                    }
                }
                cnt++;
            }
        }
    }

    vector<int> island(cnt);
    rep(i,h) rep(j,w){
        if(idx[i][j] != -1) island[idx[i][j]]++;
    }

    int m;
    cin >> m;
    rep(i,m){
        int p, q, r, s;
        cin >> p >> q >> r >> s;
        p--, q--, r--, s--;
        vector<int> res(cnt);
        int sum = 0;
        for(int x = p; x <= q; x++){
            for(int y = r; y <= s; y++){
                if(idx[x][y] != -1){
                    res[idx[x][y]]++;
                    sum++;
                }
            }
        }
        int ans = 0;
        rep(i,cnt) if(res[i] == island[i]) ans++;
        cout << sum << " " << ans << endl;
    }
    
    return 0;
}