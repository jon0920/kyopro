#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n, k;
    cin >> n >> k;
    vector<pair<int,int>> p;
    rep(i,n){
        int l, r;
        cin >> l >> r;
        p.push_back({l, 1});
        p.push_back({r, -1});
    }
    sort(p.begin(), p.end());

    int ans = 0, cnt = 0, prev = 0;
    for(auto [t, d] : p){
        if(cnt >= k) ans += t - prev;
        cnt += d;
        prev = t;
    }

    cout << ans << endl;

    return 0;
}