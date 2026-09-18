#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n, m;
    cin >> n >> m;
    vector<int> min_r(m + 2, m + 1);
    rep(i,n){
        int l, r;
        cin >> l >> r;
        min_r[l] = min(min_r[l], r);
    }

    vector<int> f(m + 2, m + 1);
    for(int i = m; i >= 1; i--){
        f[i] = min(f[i + 1], min_r[i]);
    }

    ll ans = 0;
    for(int l = 1; l <= m; l++){
        int r_lim = f[l] - 1;
        if(r_lim >= l){
            ans += (r_lim - l + 1);
        }
    }
    cout << ans << endl;

    return 0;
}