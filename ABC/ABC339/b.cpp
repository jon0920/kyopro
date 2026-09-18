#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int rotate(int r, int &x, int &y, int a, int b){
    if(r % 4 == 0){
        if(y == 0) y = a - 1;
        else y--;
    }
    else if(r % 4 == 1){
        if(x == b - 1) x = 0;
        else x++;
    }
    else if(r % 4 == 2){
        if(y == a - 1) y = 0;
        else y++;
    }
    else if(r % 4 == 3){
        if(x == 0) x = b - 1;
        else x--;
    }
    return x, y;
}

int main() {
    
    int h, w, n;
    cin >> h >> w >> n;
    vector<vector<char>> grid(h, vector<char>(w, '.'));
    int nowx = 0, nowy = 0;
    int rotation = 0;
    rep(i,n){
        if(grid[nowy][nowx] == '.'){
            grid[nowy][nowx] = '#';
            rotation++;
            rotate(rotation, nowx, nowy, h, w);
        }
        else{
            grid[nowy][nowx] = '.';
            rotation--;
            rotate(rotation, nowx, nowy, h, w);
        }
    }
    rep(i,h){
        rep(j,w){
            cout << grid[i][j];
        }
        cout << endl;
    }
    
    return 0;
}