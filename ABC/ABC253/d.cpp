#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    ll n, a, b;
    cin >> n >> a >> b;
    ll ans = n * (n + 1) / 2;
    ll d1 = n / a;
    ans -= a * d1 * (d1 + 1) / 2;
    ll d2 = n / b;
    ans -= b * d2 * (d2 + 1) / 2;
    ll d3 = n / lcm(a, b);
    ans += lcm(a, b) * d3 * (d3 + 1) / 2;

    cout << ans << endl;
    
    return 0;
}