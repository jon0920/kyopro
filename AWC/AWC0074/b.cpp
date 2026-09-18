#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    cin >> n;

    ll ans = 0, mn = 0, sum = 0;
    rep(i,n){
        ll a;
        cin >> a;
        sum += a;
        mn = min(mn, sum);
        ans = max(ans, sum - mn);
    }

    cout << ans << endl;
    
    return 0;
}