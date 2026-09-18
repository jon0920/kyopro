#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, y, m;
    cin >> n >> y >> m;
    int ny, nm;
    if(m == 12){
        ny = y + 1;
        nm = 1;
    } else {
        ny = y;
        nm = m + 1;
    }

    int ans1 = 0, ans2 = 0;
    rep(i,n){
        int a, b, p, q, c;
        cin >> a >> b >> p >> q >> c;
        if(y == p && m == q) ans1 += c;
        else if(ny == p && nm == q) ans2 += c;
    }

    cout << ans1 << " " << ans2 << endl;
    
    return 0;
}