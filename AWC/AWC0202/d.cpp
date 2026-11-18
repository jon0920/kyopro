#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i,h) cin >> s[i];

    vector<vector<int>> row(h, vector<int>(w, -1));
    vector<vector<int>> col(h, vector<int>(w, -1));

    rep(i,h){
        rep(j,w){
            if(s[i][j] == '.' && row[i][j] == -1){
                int cnt = 0;
                int x = j;
                while(x < w && s[i][x] == '.'){
                    cnt++;
                    x++;
                }
                x = j;
                while(x < w && s[i][x] == '.'){
                    row[i][x] = cnt;
                    x++;
                }
            }
        }
    }

    rep(j,w){
        rep(i,h){
            if(s[i][j] == '.' && col[i][j] == -1){
                int cnt = 0;
                int y = i;
                while(y < h && s[y][j] == '.'){
                    cnt++;
                    y++;
                }
                y = i;
                while(y < h && s[y][j] == '.'){
                    col[y][j] = cnt;
                    y++;
                }
            }
        }
    }

    int ans = -1;
    rep(i,h) rep(j,w) ans = max(ans, row[i][j] + col[i][j] - 1);
    cout << ans << endl;
    
    return 0;
}