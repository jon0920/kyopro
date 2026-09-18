#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int t;
    cin >> t;
    rep(ti,t){
        ll x1, y1, r1, x2, y2, r2;
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        ll d = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
        ll dr = (r1 - r2) * (r1 - r2);
        ll sr = (r1 + r2) * (r1 + r2);
        if(dr <= d && d <= sr) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    
    return 0;
}