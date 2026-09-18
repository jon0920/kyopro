#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    ll n, l, p, q;
    cin >> n >> l >> p >> q;
    rep(i,n){
        ll s;
        cin >> s;
        ll t;
        if(s <= l){
            t = (s * p) / 100;
        } else {
            t = (l * p + (s - l) * q) / 100;
        }
        cout << t << endl;
    }

    return 0;
}