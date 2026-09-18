#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    vector<int> point(5);
    rep(i,5) cin >> point[i];
    
    vector<pair<int,string>> ans;
    for(int bit = 1; bit < (1 << 5); bit++){
        string s = "";
        int sum = 0;
        rep(i,5){
            if(bit & (1 << i)){
                s += (char)'A' + i;
                sum += point[i];
            }
        }
        ans.push_back({sum, s});
    }
    sort(ans.begin(), ans.end(), [](const auto &x, const auto &y){
        if(x.first != y.first) return x.first > y.first;
        return x.second < y.second;
    });

    for(auto [_, s] : ans) cout << s << endl;

    return 0;
}