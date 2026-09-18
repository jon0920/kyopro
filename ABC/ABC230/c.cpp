#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    ll n, a, b;
    ll sx, lx, sy, ly;
    cin >> n >> a >> b >> sx >> lx >> sy >> ly;

    ll x = lx - sx + 1, y = ly - sy + 1;
    vector<vector<char>> grid(x, vector<char>(y, '.'));
    //op1
    {
        ll kmin = max(sx - a, sy - b);
        ll kmax = min(lx - a, ly - b);
        for(ll i = kmin; i <= kmax; i++){
            ll nx = a + i - sx, ny = b + i - sy;
            if(nx < 0 || nx >= x || ny < 0 || ny >= y)continue;
            grid[nx][ny] = '#';
        }
    }

    //op2
    {
        ll kmin = max(sx - a, b - ly);
        ll kmax = min(lx - a, b - sy);
        for(ll i = kmin; i <= kmax; i++){
            ll nx = a + i - sx, ny = b - i - sy;
            if(nx < 0 || nx >= x || ny < 0 || ny >= y) continue;
            grid[nx][ny] = '#';
        }
    }

    rep(i,x){
        rep(j,y) cout << grid[i][j];
        cout << endl;
    }
    
    return 0;
}