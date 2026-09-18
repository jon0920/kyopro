#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    cin >> n;
    rep(i,n){
        ll l, t;
        cin >> l >> t;
        if((l % t != 0) && (l % t >= t / 2)) cout << l / t + 1 << endl;
        else cout << l / t << endl;
    }    
    
    return 0;
}