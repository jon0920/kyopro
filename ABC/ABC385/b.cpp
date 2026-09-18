#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int h, w, x, y;
    cin >> h >> w >> x >> y;
    x--; y--;
    vector<string> s(h);
    string t;
    rep(i,h) cin >> s[i];
    cin >> t;

    vector<vector<bool>> visited(h,vector<bool>(w,false));
    int n = t.size();
    int ans = 0;
    rep(i,n){
        if(t[i] == 'U'){
            if(s[x-1][y] == '#') continue;
            else if(s[x-1][y] == '@' && !visited[x-1][y]){
                ans++;
                visited[x-1][y] = true;
            }
            x--;
        }
        else if(t[i] == 'D'){
            if(s[x+1][y] == '#') continue;
            else if(s[x+1][y] == '@' && !visited[x+1][y]){
                ans++;
                visited[x+1][y] = true;
            }
            x++;
        }
        else if(t[i] == 'L'){
            if(s[x][y-1] == '#') continue;
            else if(s[x][y-1] == '@' && !visited[x][y-1]){
                ans++;
                visited[x][y-1] = true;
            }
            y--;
        }
        else if(t[i] == 'R'){
            if(s[x][y+1] == '#') continue;
            else if(s[x][y+1] == '@' && !visited[x][y+1]){
                ans++;
                visited[x][y+1] = true;
            }
            y++;
        }
    }

    cout << x+1 << " " << y+1 << " " << ans << endl;
    
    return 0;
}