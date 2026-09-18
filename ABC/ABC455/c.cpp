#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    ll ans = 0;
    rep(i,n) cin >> a[i], ans += a[i];
    sort(a.begin(), a.end());
    a.push_back(-1);
    vector<ll> vec;
    ll last = a[0];
    ll cnt = 1;
    for(int i = 1; i <= n; i++){
        if(a[i] != last){
            vec.push_back(last * cnt);
            cnt = 1;
            last = a[i];
        } else cnt++;
    }

    sort(vec.rbegin(), vec.rend());
    for(int i = 0; i < min(k, (ll)vec.size()); i++) ans -= vec[i];

    cout << ans << endl;

    return 0;
}