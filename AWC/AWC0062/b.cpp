#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n, k, g;
    cin >> n >> k >> g;
    vector<ll> d(n), t(n);
    ll total = 0;
    rep(i,n){
        cin >> d[i] >> t[i];
        total += t[i];
    }

    ll sum = 0;
    rep(i,k) sum += t[i];
    ll mx = sum;

    rep(i,n-k){
        sum += t[i + k];
        sum -= t[i];
        mx = max(mx, sum);
    }

    cout << total - mx + g << endl;

    return 0;
}