#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    ll n, k;
    cin >> n >> k;
    ll sum = 0;
    vector<ll> a(n);
    rep(i,n){
        cin >> a[i];
        sum += a[i];
    }

    int cnt = 0;
    for(ll x : a){
        if(x * (n - 1) >= (__int128_t)k * (sum - x)) cnt++;
    }

    cout << cnt << endl;

    return 0;
}