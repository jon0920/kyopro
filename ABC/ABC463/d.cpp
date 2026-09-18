#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, k;
    cin >> n >> k;
    vector<pair<int,int>> lr(n);
    rep(i,n) cin >> lr[i].first >> lr[i].second;
    sort(lr.begin(), lr.end(), [](const auto &x, const auto &y){
        return x.second < y.second;
    });

    auto solve = [&](int x){
        int cnt = 0;
        ll cur = -1e18;
        for(auto [l, r] : lr){
            if(cnt == 0 || cur + x <= l){
                cnt++;
                cur = r;
            }
        }
        return cnt >= k;
    };

    ll ok = 0, ng = 1e9 + 10;
    ll ans = -1;
    while(ng - ok > 1){
        ll mid = (ng + ok) / 2;
        if(solve(mid)){
            ans = mid;
            ok = mid;
        } else {
            ng = mid;
        }
    }

    cout << ans << endl;
    
    return 0;
}