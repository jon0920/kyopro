#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    ll n, k;
    cin >> n >> k;
    k %= n;
    rep(i,n){
        cout << ((i - k + n) % n) + 1 << endl;
    }

    return 0;
}