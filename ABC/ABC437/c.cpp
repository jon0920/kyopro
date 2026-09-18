#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<pair<ll,ll>> wp(n);
        ll power = 0, weight = 0;
        rep(i,n){
            cin >> wp[i].first >> wp[i].second;
            weight += wp[i].first;
        }

        sort(wp.begin(), wp.end(), [](const auto &a, const auto &b){
            return a.first + a.second > b.first + b.second;
        });

        int cnt = n, cur = 0;
        while(power < weight){
            weight -= wp[cur].first;
            power += wp[cur].second;
            cnt--;
            cur++;
        }
        cout << cnt << endl;
    }

    return 0;
}