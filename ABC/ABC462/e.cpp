#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int t;
    cin >> t;
    while(t--){
        ll a, b, x, y;
        cin >> a >> b >> x >> y;
        if(x < 0) x *= -1;
        if(y < 0) y *= -1;

        ll ans = 2LL * min(x, y) * min(a, b);

        ll d = max(x, y) - min(x, y);

        ll p = d / 2;
        ll r = d % 2;

        ll cost1 = 0, cost2 = 0;
        if(x > y){
            cost1 = min(a, 3LL * b);
            cost2 = min({a + b, 4LL * a, 4LL * b});
        } else if(x < y){
            cost1 = min(b, 3LL * a);
            cost2 = min({a + b, 4LL * a, 4LL * b});
        }

        ans += cost2 * p + cost1 * r;
        cout << ans << endl;
    }
    
    return 0;
}