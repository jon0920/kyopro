#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];

    vector<pair<char, ll>> diff;
    rep(i,n - 1){
        if(a[i] < a[i + 1]){
            if(diff.empty() || diff.back().first == '>') diff.push_back({'<', 1});
            else diff.back().second++;
        }
        else {
            if(diff.empty() || diff.back().first == '<') diff.push_back({'>', 1});
            else diff.back().second++;
        }
    }

    int sz = diff.size();
    ll ans = 0;
    for(int i = 1; i < sz - 1; i++){
        if(diff[i].first == '>') ans += diff[i - 1].second * diff[i + 1].second;
    }
    
    cout << ans << endl;
    return 0;
}