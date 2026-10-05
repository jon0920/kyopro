#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    ll n;
    cin >> n;

    ll rn = 1;
    while((rn + 1) * (rn + 1) <= n) rn++;

    ll ans = 0;
    for(ll i = 1; i <= rn; i++) ans += ((n / i) - (n / (i + 1))) * i;
    for(ll i = 1; i <=  n / (rn + 1); i++) ans += (n / i);

    cout << ans << endl;
    
    return 0;
}