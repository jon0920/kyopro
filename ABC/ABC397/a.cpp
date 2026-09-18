#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    double x;
    cin >> x;
    int ans;
    if(x >= 38.0) ans = 1;
    else if(x < 37.5) ans = 3;
    else ans = 2;
    cout << ans << endl;
    
    return 0;
}