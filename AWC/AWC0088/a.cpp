#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    ll n, k;
    cin >> n >> k;
    ll mx = 0;
    rep(i,n){
        ll t;
        cin >> t;
        mx = max(mx, t);
    }

    cout << mx + k << endl;
    
    return 0;
}