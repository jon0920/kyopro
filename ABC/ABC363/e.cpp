#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

struct S{
    int H, x, y;
};

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

int main(){
    
    int h, w, y;
    cin >> h >> w >> y;
    vector<vector<int>> a(h, vector<int>(w));
    rep(i,h) rep(j,w) cin >> a[i][j];
    
    vector<vector<int>> sink(h, vector<int>(w, 1e9));
    auto f = [](S a, S b){
        return a.H > b.H;
    };
    priority_queue<S, vector<S>, decltype(f)> pq(f);
    rep(i,h) rep(j,w){
        if(i == 0 || j == 0 || i == h - 1 || j == w - 1){
            sink[i][j] = a[i][j];
            pq.push({a[i][j], i, j});
        }
    }

    while(!pq.empty()){
        auto [year, x, y] = pq.top(); pq.pop();
        if(year > sink[x][y]) continue;
        rep(d,4){
            int nx = x + dx[d];
            int ny = y + dy[d];
            if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
            int sink_year = max(year, a[nx][ny]);
            if(sink_year < sink[nx][ny]){
                sink[nx][ny] = sink_year;
                pq.push({sink_year, nx, ny});
            }
        }
    }

    vector<int> cnt(y + 1);
    rep(i,h) rep(j,w){
        if(sink[i][j] <= y) cnt[sink[i][j]]++;
    }

    int ans = h * w;
    for(int i = 1; i <= y; i++){
        ans -= cnt[i];
        cout << ans << endl;
    }

    return 0;
}