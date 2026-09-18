#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    ll n, m;
    cin >> n >> m;
    ll LCM = 1;
    rep(i,n){
        ll p;
        cin >> p;
        ll GCD = gcd(LCM, p);
        LCM /= GCD;
        if(m / p < LCM){
            cout << "No" << endl;
            return 0;
        }
        LCM *= p;
    }
    cout << "Yes" << endl;

    return 0;
}