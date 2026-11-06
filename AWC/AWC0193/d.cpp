#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

const ll INF = 1e18;

int main(){
    
    int n;
    cin >> n;
    pair<ll,ll> dp = {0, -INF};
    rep(i,n){
        pair<ll,ll> ndp = {-INF, -INF};
        ll a, b;
        cin >> a >> b;
        ndp.first = max(ndp.first, max(dp.first, dp.second) + a);
        ndp.second = max(ndp.second, dp.first + b);

        dp = ndp;
    }

    cout << max(dp.first, dp.second) << endl;
    
    return 0;
}