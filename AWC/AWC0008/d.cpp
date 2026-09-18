#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n, m;
    cin >> n >> m;
    vector<pair<ll,ll>> p(n);
    rep(i,n){
        ll f, d;
        cin >> f >> d;
        p[i] = {f, d};
    }

    sort(p.begin(), p.end(), [](const auto &a, const auto &b){
        if(a.first != b.first) return a.first > b.first;
        return a.second < b.second;
    });

    priority_queue<pair<ll,ll>> que;
    rep(i,n) que.push(p[i]);

    ll ans = 0;
    while(m--){
        auto [x, y] = que.top(); que.pop();
        ans += max(x, 0LL);
        x -= y;
        que.push({x, y});
    }

    cout << ans << endl;

    return 0;
}