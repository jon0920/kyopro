#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i,h) cin >> s[i];

    int x = 0, y = 0;
    while(1){
        int nx = x, ny = y;
        if(s[x][y] == 'v') nx++;
        if(s[x][y] == '>') ny++;

        if(nx >= h || ny >= w) break;
        x = nx, y = ny;
    }

    cout << x + 1 << " " << y + 1 << endl;
    
    return 0;
}