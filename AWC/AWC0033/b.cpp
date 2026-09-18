#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    ll n, k, l, r;
    cin >> n >> k >> l >> r;
    vector<ll> T;
    rep(i,n){
        int t;
        cin >> t;
        if(t < l) T.push_back(l - t);
        else if(t > r) T.push_back(t - r);
        else k--;
    }
    sort(T.begin(), T.end());

    ll ans = 0;
    rep(i,k) ans += T[i];
    cout << ans << endl;

    return 0;
}