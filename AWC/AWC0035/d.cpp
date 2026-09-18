#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n, m;
    cin >> n >> m;
    vector<ll> v(n);
    rep(i,n) cin >> v[i];
    sort(v.begin(), v.end());

    vector<pair<ll, ll>> p(m);
    rep(i,m) cin >> p[i].first >> p[i].second;
    sort(p.begin(), p.end(), [](const auto &a, const auto &b){
        auto [ai, aj] = a;
        auto [bi, bj] = b;
        return (double)ai / (double)aj < (double)bi / (double)bj;
    });
    
    int x = 0, y = 0;
    int ans = 0;
    while(x < n && y < m){
        if(v[x] * p[y].second >= p[y].first){
            ans++; x++; y++;
        } else {
            x++;
        }
    }

    cout << ans << endl;

    return 0;
}