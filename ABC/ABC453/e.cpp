#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

using mint = modint998244353;

int main(){

    int n;
    cin >> n;
    vector<pair<int,int>> lr(n);
    rep(i,n) cin >> lr[i].first >> lr[i].second;
    sort(lr.begin(), lr.end(), [](const auto &a, const auto &b){
        if(a.first != b.first) return a.first < b.first;
        return a.second < b.second;
    });

    vector<bool> ok(n, true);
    for(int k = 1; k < n - 1; k++){

    }

    return 0;
}