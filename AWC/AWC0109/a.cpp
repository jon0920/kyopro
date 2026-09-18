#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    ll n, s, k;
    cin >> n >> s >> k;
    ll ans = 0;
    rep(i,n){
        ll d;
        cin >> d;
        ans += d;
    }

    cout << ans + s + k * n << endl;
    
    return 0;
}