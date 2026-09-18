#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    
    ll cnt = 0, orv = 0;
    for(ll x : a){
        if((x | k) == k){
            cnt++;
            orv |= x;
        }
    }

    if(cnt == 0 || orv != k) cout << -1 << endl;
    else cout << cnt << endl;

    return 0;
}