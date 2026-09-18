#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, m;
    cin >> n >> m;
    ll ans = 0;
    rep(i,n){
        int a;
        cin >> a;
        if(a < 0) ans += -a;
        if(a > m) ans += a - m;
    }
    cout << ans << endl;
    
    return 0;
}