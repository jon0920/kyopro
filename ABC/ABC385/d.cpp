#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    ll n, m, sx, sy;
    cin >> n >> m >> sx >> sy;
    map<ll,set<ll>> row, col;
    rep(i,n){
        ll x, y;
        cin >> x >> y;
        row[x].insert(y);
        col[y].insert(x);
    }

    int ans = 0;
    rep(i,m){
        char d;
        ll c;
        cin >> d >> c;
        if(d == 'U'){
            ll ny = sy + c;
            auto it = row[sx].lower_bound(sy);
            while(it != row[sx].end() && *it <= ny){
                ans++;
                col[*it].erase(sx);
                it = row[sx].erase(it);
            }
            sy = ny;
        } else if(d == 'D'){
            ll ny = sy - c;
            auto it = row[sx].lower_bound(ny);
            while(it != row[sx].end() && *it <= sy){
                ans++;
                col[*it].erase(sx);
                it = row[sx].erase(it);
            }
            sy = ny;
        } else if(d == 'L'){
            ll nx = sx - c;
            auto it = col[sy].lower_bound(nx);
            while(it != col[sy].end() && *it <= sx){
                ans++;
                row[*it].erase(sy);
                it = col[sy].erase(it);
            }
            sx = nx;
        } else {
            ll nx = sx + c;
            auto it = col[sy].lower_bound(sx);
            while(it != col[sy].end() && *it <= nx){
                ans++;
                row[*it].erase(sy);
                it = col[sy].erase(it);
            }
            sx = nx;
        }
    }

    cout << sx << " " << sy << " " << ans << endl;

    return 0;
}