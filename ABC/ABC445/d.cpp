#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    ll H, W, n;
    cin >> H >> W >> n;
    map<ll,vector<int>> h, w;
    vector<pair<ll,ll>> p(n);
    rep(i,n){
        ll x, y;
        cin >> x >> y;
        h[x].push_back(i);
        w[y].push_back(i);
        p[i] = {x, y};
    }

    vector<pair<ll,ll>> ans(n);
    vector<int> used(n, 0);

    ll remH = H, remW = W;
    ll curX = 0, curY = 0;

    auto get_unused = [&](vector<int> &v, vector<int> &used){
        while(!v.empty() && used[v.back()]) v.pop_back();
        if(v.empty()) return -1;
        int id = v.back();
        v.pop_back();
        return id;
    };

    while(remH > 0 && remW > 0){
        int id = -1;

        if(h.count(remH)){
            id = get_unused(h[remH], used);
        }
        if(id != -1){
            used[id] = 1;
            ll hh = p[id].first;
            ll ww = p[id].second;

            ans[id] = {curX, curY};
            curY += ww;
            remW -= ww;
        }
        else{
            id = get_unused(w[remW], used);

            used[id] = 1;
            ll hh = p[id].first;
            ll ww = p[id].second;

            ans[id] = {curX, curY};
            curX += hh;
            remH -= hh;
        }
    }

    rep(i,n) cout << ans[i].first + 1 << " " << ans[i].second + 1 << endl;

    return 0;
}