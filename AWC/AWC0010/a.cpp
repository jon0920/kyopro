#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    ll n, m;
    cin >> n >> m;
    ll sum = 0;
    rep(i,n){
        ll a;
        cin >> a;
        sum += a;
    }

    if(sum >= m) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}