#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, q;
    cin >> n >> q;
    vector<vector<pair<int,int>>> imos(n + 1);
    while(q--){
        int l, r, x;
        cin >> l >> r >> x;
        l--;
        imos[l].push_back({1, x});
        imos[r].push_back({-1, x});
    }

    for(auto &v : imos){
        sort(v.begin(), v.end());
    }

    map<int,int> mp;
    vector<int> ans(n);
    rep(i,n){
        for(auto [e, x] : imos[i]){
            if(e == 1){
                mp[x]++;
            } else {
                mp[x]--;
                if(mp[x] == 0) mp.erase(x);
            }
        }
        ans[i] = mp.size();
    }

    for(int x : ans){
        cout << x << " ";
    }
    cout << endl;
    
    return 0;
}