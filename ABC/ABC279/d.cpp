#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    ll a, b;
    cin >> a >> b;
    double ans = (double)a;

    ll g = 2;
    ll cnt = 1;
    while(1){
        double t = (double)a / sqrt((long double)g);
        t += (double)b * cnt;
        if(ans > t){
            ans = t;
            g++;
            cnt++;
        } else break;
    }

    cout << fixed << setprecision(17);
    cout << ans << endl;
    
    return 0;
}