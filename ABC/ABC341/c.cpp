#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;


int main() {
    
    int h, w, n;
    cin >> h >> w >> n;
    string t;
    cin >> t;
    vector<string> s(h);
    rep(i,h) cin >> s[i];

    int ans = 0;
    rep(i,h) rep(j,w){
        if(s[i][j] == '.'){
            int x = j, y = i;
            bool check = true;
            for(char c : t){
                if(c == 'L' && (s[y][x - 1] == '.')) x--;
                else if(c == 'R' && (s[y][x + 1] == '.')) x++; 
                else if(c == 'U' && (s[y - 1][x] == '.')) y--; 
                else if(c == 'D' && (s[y + 1][x] == '.')) y++; 
                else check = false;
            }
            if(check) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}