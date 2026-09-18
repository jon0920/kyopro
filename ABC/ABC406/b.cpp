#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n, k;
    ll a, x = 1, y = 1;
    cin >> n >> k;

    rep(i,k) y *= 10;
    y--;

    rep(i,n){
        cin >> a;
        if(x > (y / a)) x = 1;
        else x *= a;
    }
    cout << x << endl;
    return 0;
}