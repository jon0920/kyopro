#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    cin >> n;
    ll dp0 = 0, dp1 = 0;
    rep(i,n){
        ll d;
        cin >> d;
        dp0 = max(0LL, dp0 + d);
        dp1 = min(max(0LL, dp1 + d), dp0 / 2);
    }
    cout << dp1 << endl;
    
    return 0;
}