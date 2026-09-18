#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    ll n;
    cin >> n;

    ll ans = 0;
    for(ll i = 1; i * i <= n; i++) ans++;
    cout << ans << endl;

    return 0;
}