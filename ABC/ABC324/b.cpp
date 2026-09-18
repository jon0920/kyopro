#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    ll n;
    cin >> n;
    rep(x,100) rep(y,100){
        ll ref = 1;
        rep(i,x) ref *= 2;
        rep(j,y) ref *= 3;
        if(ref == n){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    
    return 0;
}