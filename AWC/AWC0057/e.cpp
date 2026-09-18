#include <bits/stdc++.h>
#include <atcoder/fenwicktree>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n;
    cin >> n;
    vector<pair<int,int>> pv(n);
    rep(i,n) cin >> pv[i].first >> pv[i].second;
    sort(pv.begin(), pv.end());

    

    return 0;
}