#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n, l, r;
    cin >> n >> l >> r;
    vector<pair<int,int>> res;
    rep(i,n){
        int p;
        cin >> p;
        if(p >= l && p <= r){
            res.push_back({p, i + 1});
        }
    }

    if(res.empty()){
        cout << -1 << endl;
        return 0;
    }
    
    sort(res.begin(), res.end(), [](const auto &a, const auto &b){
        if(a.first != b.first) return a.first > b.first;
        return a.second < b.second;
    });

    cout << res[0].second << endl;


    return 0;
}