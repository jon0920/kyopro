#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    ll k, m;
    cin >> k >> m;
    ll sum = 0;
    rep(i,k){
        ll l;
        cin >> l;
        sum += l;
    }

    cout << sum % m << endl;

    return 0;
}