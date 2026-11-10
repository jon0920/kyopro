#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int main(){
    
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i,h) cin >> s[i];

    vector<vector<int>> g(h, vector<int>(w));
    rep(i,h) rep(j,w) g[i][j] = (s[i][j] == '1');

    int q;
    cin >> q;
    while(q--){
        int r, c;
        cin >> r >> c;
        r--, c--;
        g[r][c] ^= 1;
        rep(d,4){
            int nr = r + dx[d];
            int nc = c + dy[d];
            if(nr < 0 || nr >= h || nc < 0 || nc >= w) continue;
            g[nr][nc] ^= 1;
        }
    }

    rep(i,h){
        rep(j,w) cout << g[i][j];
        cout << endl;
    }
    
    return 0;
}