#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    ll n, c;
    cin >> n >> c;
    rep(i,n){
        ll w, a;
        cin >> w >> a;
        cout << max(0LL, w * a - c) << endl;
    }
    
    return 0;
}