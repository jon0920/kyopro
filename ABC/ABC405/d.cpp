#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

const int dx[] = {0, -1, 0, 1};
const int dy[] = {1, 0, -1, 0};
const char dir[] = {'<', 'v', '>', '^'};
const int INF = 1e9;

int main() {
    
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i,h) cin >> s[i];

    queue<pair<int,int>> que;
    rep(i,h) rep(j,w) if(s[i][j] == 'E') que.push({i,j});

    auto ng = [&](int i, int j) {
        return (i < 0 || i >= h || j < 0 || j >= w);
    };

    while(!que.empty()){
        auto [x, y] = que.front(); que.pop();
        rep(d,4){
            int nx = x + dx[d];
            int ny = y + dy[d];
            if(ng(nx,ny)) continue;
            if(s[nx][ny] != '.') continue;
            s[nx][ny] = dir[d];
            que.push({nx, ny});
        }
    }
    for(auto t : s) cout << t << endl;
    
    return 0;
}