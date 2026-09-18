#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n;
    cin >> n;
    vector<pair<int,int>> p(n);
    rep(i,n) cin >> p[i].first >> p[i].second;
    sort(p.begin(), p.end());

    int ans = 0;
    rep(i,n){
        rep(j,n){
            if(i == j) continue;
            
            auto [ix, iy] = p[i];
            auto [jx, jy] = p[j];
            if(ix >= jx || iy >= jy) continue;

            if(binary_search(p.begin(), p.end(), pair<int,int>{ix, jy}) && binary_search(p.begin(), p.end(), pair<int,int>{jx, iy})) ans++;
        }
    }

    cout << ans << endl;

    return 0;
}