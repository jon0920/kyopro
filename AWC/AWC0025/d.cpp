#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

const ll INF = 1e18;

int main(){

    ll n, s, q;
    cin >> n >> s >> q;
    vector<pair<ll,ll>> x(n);
    rep(i,n){
        ll X;
        cin >> X;
        x[i] = {X, i + 1};
    }
    x.push_back({INF, -1});
    x.push_back({-INF, -1});
    sort(x.begin(), x.end());

    

    return 0;
}