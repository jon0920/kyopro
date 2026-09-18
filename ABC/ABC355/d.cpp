#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {

    int n;
    cin >> n;
    vector<pair<int,int>> pos(n);
    rep(i,n) cin >> pos[i].first >> pos[i].second;

    sort(pos.begin(), pos.end());

    vector<int> left(n);
    rep(i,n) left[i] = pos[i].first;

    ll ans = 0;
    rep(i,n){
        int it = upper_bound(left.begin(), left.end(), pos[i].second) - left.begin() - 1;
        ans += it - i;
    }
    cout << ans << endl;
    
    return 0;
}