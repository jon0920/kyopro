#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    cin >> n;
    ll x = 0, y = 0;
    rep(i,n){
        ll a, b;
        cin >> a >> b;
        x += a; y += b;
    }

    cout << min(x, y) << endl;
    
    return 0;
}