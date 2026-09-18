#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

const ll INF = 1e18;

int main(){
    
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n){
        cin >> a[i];
        a[i]--;
    }

    vector<ll> sum(n + 1);
    rep(i,n) sum[i + 1] = sum[i] + a[i];

    ll ans = -INF;
    ll mn = INF;
    rep(i,n + 1){
        ans = max(ans, sum[i] - mn);
        mn = min(mn, sum[i]);
    }

    cout << ans << endl;
    
    return 0;
}