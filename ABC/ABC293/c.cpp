#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

const int dx[] = {0, 1};
const int dy[] = {1, 0};

int h, w;
vector<vector<int>> a;
int ans = 0;

set<int> used;
void dfs(int x, int y){
    int v = a[x][y];

    if(used.count(v)) return;
    used.insert(v);
    
    if(x == h - 1 && y == w - 1){
        ans++;
        used.erase(v);
        return;
    }
    rep(i,2){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >= h || ny >= w) continue;
        dfs(nx, ny);
    }
    used.erase(v);
}

int main(){

    cin >> h >> w;
    a.resize(h);
    rep(i,h){
        a[i].resize(w);
        rep(j,w) cin >> a[i][j];
    }
    dfs(0,0);
    cout << ans << endl;

    return 0;
}