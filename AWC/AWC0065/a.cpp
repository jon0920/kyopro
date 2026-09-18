#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n, k;
    cin >> n >> k;
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        ll a;
        cin >> a;
        if(i % k == 0 && i != n) ans++;
        ans += a;
    }

    cout << ans << endl;

    return 0;
}