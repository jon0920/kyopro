#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    cin >> n;
    ll ans = 0;
    rep(i,n){
        ll a, b;
        cin >> a >> b;
        ans += max(0LL, a - b);
    }
    cout << ans << endl;
    
    return 0;
}