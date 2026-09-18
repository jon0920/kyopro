#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    ll x;
    cin >> x;
    int ans = 1;
    bool ok = false;
    while(1){
        x /= ans;
        if(x == 1) break;
        ans++;
    }
    cout << ans << endl;
    return 0;
}