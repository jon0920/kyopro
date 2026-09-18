#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n, k;
    cin >> n >> k;
    vector<pair<int,int>> ba(n);
    rep(i,n){
        int a, b;
        cin >> a >> b;
        ba[i] = {b, a};
    }
    sort(ba.rbegin(), ba.rend());

    priority_queue<ll> pq;
    ll s = 0;
    rep(i,k){
        s += ba[i].second;
        pq.push(-ba[i].second);
    }
    ll ans = s * ba[k - 1].first;

    for(int i = k; i < n; i++){
        auto [b, a] = ba[i];
        s += a;
        pq.push(-a);
        s += pq.top();
        pq.pop();
        ans = max(ans, s * b);
    }

    cout << ans << endl;

    return 0;
}