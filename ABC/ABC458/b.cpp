#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

int main(){
    
    int h, w;
    cin >> h >> w;
    vector<vector<int>> ans(h, vector<int>(w));
    rep(i,h) rep(j,w){
        int cnt = 0;
        rep(d,4){
            int x = i + dx[d];
            int y = j + dy[d];
            if(x < 0 || x >= h || y < 0 || y >= w) continue;
            cnt++;
        }
        ans[i][j] = cnt;
    }

    rep(i,h){
        rep(j,w) cout << ans[i][j] << " ";
        cout << endl;
    }
    
    return 0;
}