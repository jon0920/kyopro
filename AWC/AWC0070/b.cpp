#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    cin >> n;
    ll sum = 0;
    int ans = 0;
    for(ll k = 1; k <= n; k++){
        ll a;
        cin >> a;
        sum += a;
        if(k * a >= sum) ans++;
    }

    cout << ans << endl;
    
    return 0;
}