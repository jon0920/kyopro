#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    ll n, l, k;
    cin >> n >> l >> k;
    k++;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    sort(a.begin(), a.end());
    int ans = 0;
    rep(i,n){
        if(l >= a[i] && k > 0){
            l -= a[i];
            ans++;
            k--;
        } else {
            break;
        }
    }
    cout << ans << endl;

    return 0;
}