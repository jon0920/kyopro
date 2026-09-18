#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n, q;
    cin >> n >> q;
    vector<pair<ll,ll>> yp(n);
    rep(i,n){
        ll y, p;
        cin >> y >> p;
        yp[i] = {y, p};
    }
    sort(yp.begin(), yp.end());
    vector<ll> y(n);
    rep(i,n) y[i] = yp[i].first;
    
    vector<ll> sum(n + 1);
    rep(i,n) sum[i + 1] = sum[i] + yp[i].second;

    while(q--){
        int l;
        cin >> l;
        int it = lower_bound(y.begin(), y.end(), l) - y.begin();
        cout << sum[n] - sum[it] << endl;
    }

    return 0;
}