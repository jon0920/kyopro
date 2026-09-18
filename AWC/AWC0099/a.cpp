#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    ll n, w;
    cin >> n >> w;
    vector<ll> c(n);
    rep(i,n) cin >> c[i];
    int ans = 0;
    rep(i,n){
        if(w >= c[i]){
            w -= c[i];
            ans++;
        } else {
            break;
        }
    }

    cout << ans << endl;
    
    return 0;
}