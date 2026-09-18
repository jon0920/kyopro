#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n, m;
    cin >> n >> m;
    vector<pair<ll,ll>> ck(n);
    rep(i,n){
        ll c, k;
        cin >> c >> k;
        ck[i] = {c, k};
    }

    ll ans = 0;
    rep(i,m){
        int p;
        cin >> p;
        p--;
        if(ck[p].second > 0){
            ans += ck[p].first;
            ck[p].second--;
        }
    }
    cout << ans << endl;

    return 0;
}