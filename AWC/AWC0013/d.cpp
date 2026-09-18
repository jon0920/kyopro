#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n, m;
    cin >> n >> m;
    vector<vector<ll>> a(m, vector<ll>(n));
    rep(i,n) rep(j,m){
        cin >> a[j][i];
    }

    for(auto &v : a) sort(v.rbegin(), v.rend());

    ll ans = 0;
    rep(i,m) rep(j,n){
        ans += a[i][j] * ((n - 1 - j) - j);
        //(n - 1 - j) <- プラスとして寄与する要素数
        //j <- マイナスとして寄与する要素数
    }
    cout << ans << endl;

    return 0;
}