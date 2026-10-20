#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, q;
    cin >> n >> q;
    vector<ll> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    vector<ll> sum0(n + 1), sum1(n + 1), sum2(n + 1);
    for(ll i = 1; i <= n; i++){
        sum0[i] = sum0[i - 1] + a[i];
        sum1[i] = sum1[i - 1] + i * a[i];
        sum2[i] = sum2[i - 1] + i * i * a[i];
    }

    while(q--){
        ll l, r;
        cin >> l >> r;
        ll s1 = -(sum2[r] - sum2[l - 1]);
        ll s2 = (l + r) * (sum1[r] - sum1[l - 1]);
        ll s3 = -(l - 1) * (r + 1) * (sum0[r] - sum0[l - 1]);

        cout << s1 + s2 + s3 << endl;
    }
    
    return 0;
}