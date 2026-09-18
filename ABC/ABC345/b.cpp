#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    ll x;
    cin >> x;
    if(x % 10 == 0 || x < 0) cout << x / 10 << endl;
    else cout << x / 10 + 1 << endl;
    
    return 0;
}