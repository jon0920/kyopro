#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int t;
    cin >> t;
    rep(ti,t){
        ll px, py, qx, qy, rx, ry, sx, sy;
        cin >> px >> py >> qx >> qy >> rx >> ry >> sx >> sy;
        ll v1x = qx - px, v1y = qy - py;
        ll v2x = sx - rx, v2y = sy - ry;

        if((v1x * v2y) - (v1y * v2x) != 0) cout << "Yes" << endl;
        else {
            px *= 2; py *= 2; qx *= 2; qy *= 2;
            rx *= 2; ry *= 2; sx *= 2; sy *= 2;
            v1x = qx - px, v1y = qy - py;
            v2x = sx - rx, v2y = sy - ry;
            ll m1x = (qx + px) / 2, m1y = (qy + py) / 2;
            ll m2x = (sx + rx) / 2, m2y = (sy + ry) / 2;
            if(m1x * v1x + m1y * v1y == 0) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
    
    return 0;
}