#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, d;
    cin >> n >> d;
    vector<pair<ll,ll>> cp(n);
    bool positive = false;
    rep(i,n){
        cin >> cp[i].first >> cp[i].second;
        if(cp[i].second - cp[i].first > 0) positive = true;
    }

    if(!positive){
        sort(cp.begin(), cp.end(), [](const auto &x, const auto &y){
            return x.second - x.first > y.second - y.first;
        });
        cout << cp[0].second - cp[0].first << endl;
    } else {
        vector<pair<ll,ll>> v;
        rep(i,n){
            if(cp[i].second - cp[i].first > 0) v.push_back(cp[i]);
        }
        sort(v.begin(), v.end(), [](const auto &x, const auto &y){
            return x.second < y.second;
        });

        int m = v.size();
        int r = 0;
        ll sum = 0;
        ll ans = 0;
        rep(l,m){
            while(r < m && v[r].second - v[l].second <= d){
                sum += v[r].second - v[r].first;
                r++;
            }
            ans = max(ans, sum);
            sum -= v[l].second - v[l].first;
        }   
        cout << ans << endl;
    }

    return 0;
}