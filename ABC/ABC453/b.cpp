#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int t, x;
    cin >> t >> x;
    vector<int> a(t + 1);
    rep(i,t + 1) cin >> a[i];

    vector<pair<int,int>> ans;
    ans.push_back({0, a[0]});

    for(int i = 1; i <= t; i++){
        if(abs(ans.back().second - a[i]) >= x){
            ans.push_back({i, a[i]});
        }
    }

    for(auto [x, y] : ans) cout << x << " " << y << endl;
    

    return 0;
}