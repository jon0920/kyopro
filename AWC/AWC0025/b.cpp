#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int h, w, n;
    cin >> h >> w >> n;
    vector<string> s(h);
    rep(i,h) cin >> s[i];
    int sum = 0;
    rep(i,h) rep(j,w) if(s[i][j] == '#') sum++;
    string t;
    cin >> t;

    int x = 0, y = 0;
    int cnt = 0;
    if(s[x][y] == '#'){
        cnt++; s[x][y] = '.';
    }

    for(char c : t){
        if(c == 'U' && x != 0) x--;
        else if(c == 'D' && x != h - 1) x++;
        else if(c == 'L' && y != 0) y--;
        else if(c == 'R' && y != w - 1) y++;

        if(s[x][y] == '#'){
            cnt++; s[x][y] = '.';
        }
    }
    cout << sum - cnt << endl;

    return 0;
}