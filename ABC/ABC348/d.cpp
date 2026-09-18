#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

int main(){
    
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    int sx, sy, tx, ty;
    rep(i,h){
        cin >> s[i];
        rep(j,w){
            if(s[i][j] == 'S') sx = i, sy = j;
            if(s[i][j] == 'T') tx = i, ty = j;
        }
    }

    int n;
    cin >> n;
    vector<int> r(n), c(n), e(n);
    vector<vector<int>> medicine(h, vector<int>(w, -1));
    int si = -1, ti = n;
    rep(i,n){
        cin >> r[i] >> c[i] >> e[i];
        r[i]--, c[i]--;
        if(r[i] == sx && c[i] == sy) si = i;
        if(r[i] == tx && c[i] == ty) ti = i;
        medicine[r[i]][c[i]] = i;
    }
    if(medicine[tx][ty] == -1) medicine[tx][ty] = n;
    if(si == -1){
        cout << "No" << endl;
        return 0;
    }

    vector<vector<int>> G(n + 1);
    rep(i,n){
        int x = r[i], y = c[i], E = e[i];
        vector<vector<int>> dist(h, vector<int>(w, -1));
        dist[x][y] = 0;
        queue<pair<int,int>> que;
        que.push({x, y});
        while(!que.empty()){
            auto [xx, yy] = que.front(); que.pop();
            rep(d,4){
                int nx = xx + dx[d];
                int ny = yy + dy[d];
                if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
                if(s[nx][ny] == '#') continue;
                if(dist[nx][ny] != -1) continue;
                
                dist[nx][ny] = dist[xx][yy] + 1;
                if(medicine[nx][ny] != -1){
                    G[i].push_back(medicine[nx][ny]);
                }
                if(dist[nx][ny] != E) que.push({nx, ny});
            }
        }
    }

    vector<bool> seen(n + 1);
    seen[si] = true;
    queue<int> que;
    que.push(si);

    while(!que.empty()){
        int v = que.front(); que.pop();
        for(auto nv : G[v]){
            if(!seen[nv]){
                seen[nv] = true;
                que.push(nv);
            }
        }
    }

    if(seen[ti]) cout << "Yes" << endl;
    else cout << "No" << endl;
    
    return 0;
}