#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    ll q, v;
    cin >> q >> v;
    priority_queue<ll> pq;
    rep(i,q){
        int type;
        cin >> type;
        if(type == 1){
            ll t, w;
            cin >> t >> w;
            pq.push(w - t);
        } else {
            ll t;
            cin >> t;
            if(pq.empty()) cout << -1 << endl;
            else{
                cout << min(pq.top() + t, v) << endl;
                pq.pop();
            }
        }
    }
    
    return 0;
}