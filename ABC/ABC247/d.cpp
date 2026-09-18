#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int q;
    cin >> q;
    deque<pair<ll,ll>> dq;
    while(q--){
        int type;
        cin >> type;
        if(type == 1){
            ll x, c;
            cin >> x >> c;
            dq.push_back({x, c});
        } else {
            ll c;
            cin >> c;
            ll res = 0;
            while(c > 0){
                if(dq.front().second >= c){
                    res += dq.front().first * c;
                    dq.front().second -= c;
                    c = 0;
                } else {
                    res += dq.front().first * dq.front().second;
                    c -= dq.front().second;
                    dq.pop_front();
                }
            }
            cout << res << endl;
        }
    }
    
    return 0;
}