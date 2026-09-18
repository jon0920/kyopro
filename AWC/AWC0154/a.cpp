#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    ll n, p;
    cin >> n >> p;
    double ans = 0.0;
    rep(i,n){
        ll x, v;
        cin >> x >> v;
        if(p == x) continue;
        ll d = abs(x - p);
        ans += (double)v / d; 
    }
    cout << fixed << setprecision(17);
    cout << ans << endl;
    
    return 0;
}