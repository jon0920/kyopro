#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n, d;
    cin >> n >> d;
    vector<pair<int,int>> p(n);
    rep(i,n){
        int l, r;
        cin >> l >> r;
        l--, r--;
        p[i] = {l, r};
    }
    sort(p.begin(), p.end(), [](const auto &a, const auto &b){
        return a.second < b.second;
    });

    int ans = 0, now = -1e9;
    for(auto &[l, r] : p){
        if(now + d - 1 < l){
            ans++;
            now = r;
        }
    }
    cout << ans << endl;

    return 0;
}