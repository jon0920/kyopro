#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int q;
    cin >> q;
    deque<pair<ll,ll>> que;

    ll last_place = 0;
    ll m = 0;
    rep(i,q){
        int type;
        cin >> type;
        if(type == 1){
            ll l;
            cin >> l;
            que.push_back({last_place, last_place + l});
            last_place += l;
        }
        else if(type == 2){
            m += que.front().second - que.front().first;
            que.pop_front();
        }
        else{
            ll k;
            cin >> k;
            k--;
            auto [f, s] = que[k];
            ll ans = f - m; 
            cout << ans << endl;
        }
    }
    
    return 0;
}