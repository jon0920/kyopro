#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

struct S{
    ll power; int x; int y;
};

int main(){

    ll h, w, X, p, q;
    cin >> h >> w >> X >> p >> q;
    p--, q--;
    vector<vector<ll>> s(h, vector<ll>(w));
    rep(i,h) rep(j,w) cin >> s[i][j];

    ll pow = s[p][q];
    vector<vector<bool>> seen(h, vector<bool>(w));
    seen[p][q] = true;

    auto f = [](S a, S b){
        return a.power > b.power;
    };

    priority_queue<S, vector<S>, decltype(f)> pq(f);
    rep(d,4){
        int x = p + dx[d];
        int y = q + dy[d];
        if(x < 0 || x >= h || y < 0 || y >= w) continue;
        seen[x][y] = true;
        pq.push({s[x][y], x, y});
    }

    while(!pq.empty()){
        auto [P, x, y] = pq.top(); pq.pop();
        if((__int128_t)pow <= (__int128_t)P * X) break; 
        
        pow += s[x][y];
        rep(d,4){
            int nx = x + dx[d];
            int ny = y + dy[d];
            if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
            if(seen[nx][ny]) continue;

            seen[nx][ny] = true;
            pq.push({s[nx][ny], nx, ny});
        }
    }

    cout << pow << endl;

    return 0;
}