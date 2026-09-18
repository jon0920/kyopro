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
    for(int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i - 1];

    while(q--){
        int l, r;
        cin >> l >> r;
        l--;
        cout << sum[r] - sum[l] << endl;
    }

    return 0;
}