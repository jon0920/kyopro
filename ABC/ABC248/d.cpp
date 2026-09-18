#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    cin >> n;
    map<int,vector<int>> mp;
    rep(i,n){
        int a;
        cin >> a;
        mp[a].push_back(i);
    }

    int q;
    cin >> q;
    while(q--){
        int l, r, x;
        cin >> l >> r >> x;
        l--; r--;
        if(!mp.count(x)) cout << 0 << endl;
        else {
            int left = lower_bound(mp[x].begin(), mp[x].end(), l) - mp[x].begin();
            int right = upper_bound(mp[x].begin(), mp[x].end(), r) - mp[x].begin();
            cout << right - left << endl;
        }
    }
    
    return 0;
}