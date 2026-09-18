#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int t;
    cin >> t;
    rep(ti,t){
        ll a, b, x, y;
        cin >> a >> b >> x >> y;
        x = abs(x), y = abs(y);
        ll mn = min(x, y), mx = max(x, y);
        ll d = mx - mn;
        ll ans = 0;

        ans += mn * (min(a, b)) * 2;

        ll cost2 = min({a + b, 4 * a, 4 * b});
        ans += cost2 * (d / 2);

        if(d % 2 == 1){
            if(x > y) ans += min(a, 3 * b);
            else ans += min(b, 3 * a);
        }
        cout << ans << endl;
    }
    
    return 0;
}