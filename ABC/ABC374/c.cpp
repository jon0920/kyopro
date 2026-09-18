#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n;
    cin >> n;
    vector<ll> k(n);
    ll allsum = 0;
    rep(i,n){
        cin >> k[i];
        allsum += k[i];
    }

    ll ans = 1e9;
    for(int bit = 0; bit < (1 << n); bit++){
        ll sum = 0;
        for(int i = 0; i < n; i++){
            if(bit & (1 << i)) sum += k[i]; 
        }
        ans = min(ans, max(sum, allsum - sum));
    }

    cout << ans << endl;
    
    return 0;
}