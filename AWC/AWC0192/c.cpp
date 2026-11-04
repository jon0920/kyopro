#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    ll n, k;
    cin >> n >> k;
    vector<pair<ll,ll>> cand;
    rep(i,n){
        ll a, b;
        cin >> a >> b;
        if(a + b >= k) cand.push_back({a + b, i});
    }

    sort(cand.begin(), cand.end(), [](const auto &a, const auto &b){
        if(a.first != b.first) return a.first > b.first;
        return a.second < b.second;
    });

    vector<int> res(n, -1);
    int num = 1;
    for(auto [_, i] : cand){
        res[i] = num;
        num++;
    }

    for(int x : res) cout << x << endl;
    
    return 0;
}