#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    map<int,pair<int,int>> mp;
    rep(i,n){
        int prev = (i == 0) ? -1 : a[i - 1];
        int nxt = (i == n -1) ? -1 : a[i + 1];
        mp[a[i]] = {prev, nxt};
    }

    int q;
    cin >> q;
    while(q--){
        int type;
        cin >> type;
        if(type == 1){
            int x, y;
            cin >> x >> y;
            auto [a, b] = mp[x];
            mp[y] = {x, b};
            mp[x].second = y;
            if(b != -1) mp[b].first = y;
        } else {
            int x;
            cin >> x;
            auto [a, b] = mp[x];
            if(a != -1) mp[a].second = b;
            if(b != -1) mp[b].first = a;
            mp.erase(x);
        }
    }

    int crr;
    for(auto [k, v] : mp){
        if(v.first == -1){
            crr = k;
            break;
        }
    }

    vector<int> ans;
    while(crr != -1){
        ans.push_back(crr);
        crr = mp[crr].second;
    }

    for(auto x : ans) cout << x << " ";
    cout << endl;
    
    return 0;
}