#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    cin >> n;
    ll ans = 0;
    for(ll i = 1; i < n; i++){
        ll b;
        cin >> b;
        ans += b * i;
    }

    cout << ans << endl;
    
    return 0;
}