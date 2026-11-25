#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, q;
    cin >> n >> q;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    vector<ll> sum(n + 1);
    rep(i,n) sum[i + 1] = sum[i] + a[i];

    while(q--){
        ll l, r, t;
        cin >> l >> r >> t;
        l--;
        cout << (sum[r] - sum[l]) * t << endl;
    }
    
    return 0;
}