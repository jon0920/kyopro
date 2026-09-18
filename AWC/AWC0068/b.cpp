#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n, m;
    cin >> n >> m;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    vector<pair<int,int>> lr(m);
    rep(i,m){
        cin >> lr[i].first >> lr[i].second;
        lr[i].first--;
        lr[i].second--;
    }
    sort(lr.begin(), lr.end());

    vector<ll> res;
    for(auto [x, y] : lr){
        ll sum = 0;
        for(int i = x; i <= y; i++) sum += a[i];
        res.push_back(sum);
    }

    cout << *max_element(res.begin(), res.end()) - *min_element(res.begin(), res.end()) << endl;

    return 0;
}