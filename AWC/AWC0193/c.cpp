#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i,h) cin >> s[i];

    int ans = 0;
    vector<vector<bool>> seen(h, vector<bool>(w));
    pair<int,int> cur = {0, 0};
    while(1){
        auto [x, y] = cur;
        if(seen[x][y]){
            ans = -1;
            break;
        }
        seen[x][y] = true;
        auto [nx, ny] = cur;
        if(s[x][y] == 'R') ny++;
        else if(s[x][y] == 'L') ny--;
        else if(s[x][y] == 'U') nx--;
        else nx++;

        if(nx < 0 || nx >= h || ny < 0 || ny >= w) break;
        ans++;
        cur = {nx, ny};
    }

    cout << ans << endl;
    
    return 0;
}