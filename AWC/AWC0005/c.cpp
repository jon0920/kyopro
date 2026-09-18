#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    ll n, k;
    cin >> n >> k;
    priority_queue<pair<ll,int>> que;
    vector<ll> a(n);
    rep(i,n){
        cin >> a[i];
        que.push({a[i], i});
    }
    vector<ll> ref = a;

    while(!que.empty()){
        auto [x, i] = que.top(); que.pop();
        if(x != a[i]) continue;
        if(i - 1 >= 0){
            if(a[i - 1] < x - k){
                a[i - 1] = x - k;
                que.push({a[i - 1], i - 1});
            }
        }
        if(i + 1 < n){
            if(a[i + 1] < x - k){
                a[i + 1] = x - k;
                que.push({a[i + 1], i + 1});
            }
        }
    }

    ll ans = 0;
    rep(i,n) ans += a[i] - ref[i];
    cout << ans << endl;

    return 0;
}