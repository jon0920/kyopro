#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n;
    cin >> n;
    vector<pair<int,int>> lr(n);
    rep(i,n) cin >> lr[i].first >> lr[i].second;
    sort(lr.begin(), lr.end(), [](const auto &a, const auto &b){
        if(a.second != b.second) return a.second < b.second;
        return a.first < b.first;
    });

    int ans = 0;
    int crr = -1;
    rep(i,n){
        auto [l, r] = lr[i];
        if(crr <= l){
            ans++;
            crr = r;
        }
    }

    cout << ans << endl;

    return 0;
}