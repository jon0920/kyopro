#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    cin >> n;
    ll x = 1;
    vector<ll> t(n);
    rep(i,n){
        cin >> t[i];
        x = lcm(x, t[i] / gcd(t[0], t[i]));
    }

    cout << x << "/1" << endl;
    
    return 0;
}