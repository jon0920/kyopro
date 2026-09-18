#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    ll n, s, c;
    cin >> n >> s >> c;
    rep(i,n){
        ll r;
        cin >> r;
        s -= r;
    }

    s *= -1;
    cout << max(0LL, s * c) << endl;
    
    return 0;
}