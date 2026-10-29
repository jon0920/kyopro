#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

const ll INF = 1e18;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

struct S{
    ll d, x, y;
    bool operator>(const S& other) const {
        return d > other.d;
    }
};

int main(){
    
    int h, w;
    cin >> h >> w;
    vector<vector<ll>> a(h, vector<ll>(w));
    rep(i,h) rep(j,w) cin >> a[i][j];

    vector<vector<ll>> dist(h, vector<ll>(w, INF));
    dist[0][0] = 0;
    priority_queue<S, vector<S>, greater<S>> pq;
    pq.push({0, 0, 0});
    
    while(!pq.empty()){
        auto [c, x, y] = pq.top();
        pq.pop();
        if(dist[x][y] != c) continue;
        rep(dir,4){
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
            if(dist[nx][ny] <= dist[x][y] + a[nx][ny]) continue;

            dist[nx][ny] = dist[x][y] + a[nx][ny];
            pq.push({dist[nx][ny], nx, ny});
        }
    }

    cout << dist[h - 1][w - 1] << endl;
    
    return 0;
}