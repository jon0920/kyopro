#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    ll n, m, k;
    cin >> n >> m >> k;
    ll lcm = (n * m) / gcd(n,m);

    ll l = 0, r = 2e18, mid, y;
    while(l + 1 < r){
        mid = (l + r) / 2;
        y = (mid / n) + (mid / m) - 2 * (mid / lcm);
        if(y < k) l = mid;
        else r = mid;
    }
    cout << r << endl;
    
    return 0;
}