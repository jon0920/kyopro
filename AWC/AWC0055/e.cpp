#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    ll n, k;
    cin >> n >> k;
    vector<pair<ll,ll>> ab(n);
    rep(i,n) cin >> ab[i].first >> ab[i].second;

    vector<pair<ll,ll>> left(ab.begin(), ab.begin() + n / 2);
    vector<pair<ll,ll>> right(ab.begin() + n / 2, ab.end());

    auto gen = [&](vector<pair<ll,ll>> vec){
        vector<ll> res = {0};
        for(auto [x, y] : vec){
            int sz = res.size();
            rep(i,sz){
                res.push_back(res[i] + x);
                res.push_back(res[i] + y);
            }
        }
        return res;
    };

    auto L = gen(left);
    auto R = gen(right);
    set<ll> Rst(R.begin(), R.end());

    for(auto x : L){
        if(Rst.count(k - x)){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;

    return 0;
}