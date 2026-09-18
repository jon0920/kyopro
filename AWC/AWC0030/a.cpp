#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    ll n, m;
    cin >> n >> m;
    rep(i,n){
        ll a;
        cin >> a;
        cout << a / m << ' ' << a % m << endl;
    }

    return 0;
}