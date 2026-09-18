#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    ll n, l, w;
    cin >> n >> l >> w;
    int ans = 0;
    rep(i,n){
        ll d;
        cin >> d;
        if(d >= l - w && d <= l + w) ans++;
    }
    cout << ans << endl;

    return 0;
}