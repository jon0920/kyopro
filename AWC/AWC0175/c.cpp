#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    cin >> n;
    vector<ll> h(n);
    rep(i,n) cin >> h[i];

    if(n <= 2){
        cout << 0 << endl;
        return 0;
    }

    ll ans = 0;
    for(int i = 1; i < n - 1; i++){
        if(h[i - 1] > h[i] && h[i] < h[i + 1]){
            ans += min(h[i - 1] - h[i], h[i + 1] - h[i]);
        }
    }
    
    cout << ans << endl;
    
    return 0;
}