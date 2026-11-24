#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

const int INF = 1e9;

int main(){
    
    int n, q;
    cin >> n >> q;

    vector<int> cnt(n, 1);
    map<int,pair<int,int>> mp;
    mp[-INF] = {-INF, -INF};
    mp[INF] = {INF, INF};
    rep(i,n){
        mp[i] = {i, i};
    }

    while(q--){
        int type;
        cin >> type;
        if(type == 1){
            int x, c;
            cin >> x >> c;
            x--, c--;
            auto it = mp.upper_bound(x);
            it--;
            int l = it->first;
            auto [r, pre_c] = it->second;
            cnt[pre_c] -= r - l + 1;

            int nl = l, nr = r;
            if(it != mp.begin()){
                auto pre_it = prev(it);
                if(pre_it->second.second == c){
                    nl = pre_it->first;
                    mp.erase(pre_it);
                }
            }
            if(it != mp.end()){
                auto nxt_it = next(it);
                if(nxt_it->second.second == c){
                    nr = nxt_it->second.first;
                    mp.erase(nxt_it);
                }
            }

            mp.erase(it);
            mp[nl] = {nr, c};

            cnt[c] += r - l + 1;
        } else {
            int c;
            cin >> c;
            cout << cnt[c - 1] << endl;
        }
    }
    
    return 0;
}