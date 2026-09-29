#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

//構造体優先度付きキュー
struct S{
    ll cost;
    int x; int y;
    bool operator>(const S &other) const {
        return cost > other.cost;
    }
};

const ll INF = 1e18;

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

int main(){
    
    int h, w;
    cin >> h >> w;
    vector<vector<ll>> c(h, vector<ll>(w));
    vector<vector<ll>> dist(h, vector<ll>(w, INF));
    priority_queue<S, vector<S>, greater<S>> pq;
    rep(i,h){
        rep(j,w){
            cin >> c[i][j];
            if(i == 0 || j == 0 || i == h - 1 || j == w - 1){
                pq.push({c[i][j], i, j});
                dist[i][j] = c[i][j];
            }
        }
    }

    while(!pq.empty()){
        auto [cost, x, y] = pq.top(); pq.pop();
        if(cost != dist[x][y]) continue;
        rep(dir,4){
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
            if(dist[nx][ny] <= cost + c[nx][ny]) continue;
            dist[nx][ny] = cost + c[nx][ny];
            pq.push({dist[nx][ny], nx, ny});
        }
    }

    int q;
    cin >> q;
    while(q--){
        int r, k;
        cin >> r >> k;
        r--, k--;
        cout << dist[r][k] << endl;
    }

    return 0;
}