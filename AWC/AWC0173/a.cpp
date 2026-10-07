#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    ll n, b;
    cin >> n >> b;
    ll sum = 0;
    rep(i,n){
        ll a;
        cin >> a;
        sum += a;
    }

    cout << (sum <= b ? "Yes" : "No") << endl;
    
    return 0;
}