#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

const int INF = 1e9;

int main(){
    
    int n, q;
    cin >> n >> q;
    map<int,pair<int,int>> mp;
    mp[-INF] = {INF, INF};
    mp[INF] = {INF, INF};
    //mp[L] = {R, color}
    rep(i,n) mp[i] = {i, i};

    vector<int> cnt(n, 1);

    while(q--){
        int type;
        cin >> type;
        if(type == 1){
            int x, c;
            cin >> x >> c;
            x--, c--;
            auto it = mp.lower_bound(x);
            int L = it->first;
            int R = it->second.first;
            int pre_c = it->second.second;

            cnt[pre_c] -= R - L + 1;
            cnt[c] += R - L + 1;

            int NL = L, NR = R;
            if(it != mp.begin()){
                auto pre = prev(it);
                if(pre->second.second == c){
                    NL = pre->first;
                    mp.erase(pre);
                }
            }
            if(it != mp.end()){
                auto nxt = next(it);
                if(nxt->second.second == c){
                    NR = nxt->second.first;
                    mp.erase(nxt);
                }
            }

            mp.erase(it);
            mp[NL] = {NR, c};
        } else {
            int c;
            cin >> c;
            c--;
            cout << cnt[c] << endl;
        }
    }
    
    return 0;
}