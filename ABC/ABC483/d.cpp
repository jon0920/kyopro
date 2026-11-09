#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    cin >> n;
    vector<ll> a(n + 1), pre(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }

    vector<ll> pre_min(n + 1), pre_max(n + 1);
    vector<ll> suf_min(n + 1), suf_max(n + 1);

    pre_min[0] = pre_max[0] = pre[0];
    for(int i = 1; i <= n; i++){
        pre_min[i] = min(pre_min[i - 1], pre[i]);
        pre_max[i] = max(pre_max[i - 1], pre[i]);
    }

    suf_min[n] = suf_max[n] = pre[n];
    for(int i = n - 1; i >= 0; i--){
        suf_min[i] = min(suf_min[i + 1], pre[i]);
        suf_max[i] = max(suf_max[i + 1], pre[i]);
    }

    ll ans = pre_max[n] - pre_min[n] + 1;
    for(int i = 1; i <= n; i++){
        ll d = -2 * a[i];
        ll mx = max(pre_max[i - 1], suf_max[i] + d);
        ll mn = min(pre_min[i - 1], suf_min[i] + d);
        ans = max(ans, mx - mn + 1);
    }
    cout << ans << endl;
    
    return 0;
}