#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, q;
    cin >> n >> q;
    map<string,vector<int>> mp;
    rep(i,n){
        string s;
        cin >> s;
        mp[s].push_back(i);
    }

    while(q--){
        int l, r;
        string t;
        cin >> l >> r >> t;
        l--, r--;
        if(!mp.count(t)){
            cout << 0 << endl;
        } else {
            int ans = upper_bound(mp[t].begin(), mp[t].end(), r) - lower_bound(mp[t].begin(), mp[t].end(), l);
            cout << ans << endl;
        }
    }
    
    return 0;
}