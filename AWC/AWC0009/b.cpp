#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    ll n, s, c;
    cin >> n >> s >> c;
    ll ans = 0;
    rep(i,n){
        ll h, p;
        cin >> h >> p;
        if(s < h) ans += c;
        else s = s - h + p;
    }

    cout << ans << endl;

    return 0;
}