#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    vector<pair<int,int>> pos(4);
    rep(i,4) cin >> pos[i].first >> pos[i].second;

    bool ok = true;
    rep(i,4){
        auto [x0, y0] = pos[i];
        auto [x1, y1] = pos[(i + 1) % 4];
        auto [x2, y2] = pos[(i - 1 + 4) % 4];
        int ax = x1 - x0, ay = y1 - y0;
        int bx = x2 - x0, by = y2 - y0;
        if(ax * by - ay * bx < 0) ok = false;
    }
    cout << (ok ? "Yes" : "No") << endl;
    
    return 0;
}