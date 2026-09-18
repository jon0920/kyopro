#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    ll n, d;
    cin >> n >> d;
    int ans = 0;
    rep(i,n){
        ll x, y;
        cin >> x >> y;
        if(x * x + y * y > d * d) ans++;
    }
    cout << ans << endl;
    
    return 0;
}