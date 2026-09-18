#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    ll n, m;
    cin >> n >> m;
    ll ans = 0;
    rep(i,m + 1){
        ans += pow(n,i);
        if(ans > 1e9) {
            cout << "inf" << endl;
            return 0;
        }
    }

    
    cout << ans << endl;
    
    return 0;
}