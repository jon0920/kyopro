#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n;
    cin >> n;
    vector<int> a(n);
    map<int,ll> pre, suf;
    rep(i,n){
        cin >> a[i];
        if(i) suf[a[i]]++;
    }

    ll ans = 0;
    rep(i,n){
        ll y = a[i];
        if(y % 5 == 0){
            ll x = y / 5 * 3;
            ll z = y / 5 * 7;
            if(pre.count(x) && pre.count(z)){
                ans += pre[x] * pre[z];
            }
            if(suf.count(x) && suf.count(z)){
                ans += suf[x] * suf[z];
            }
        }
        pre[a[i]]++;
        if(i)suf[a[i]]--;
    }
    cout << ans << endl;

    return 0;
}