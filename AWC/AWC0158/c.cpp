#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

struct S{
    ll t; ll w; ll pos;
};

int main(){
    
    int n, v, q;
    cin >> n >> v >> q;
    vector<S> event(n);
    rep(i,n){
        ll t, w;
        cin >> t >> w;
        if(i == 0) event[i] = {t, w + (w < 0 ? -v : v), 0};
        else{
            auto [pt, pw, ppos] = event[i - 1];
            ll npos = ppos + (t - pt) * pw;
            event[i] = {t, w + (w < 0 ? -v : v), npos};
        }
    }

    while(q--){
        int t;
        cin >> t;
        auto it = upper_bound(event.begin(), event.end(), t, [](int val, const S &v){
                return val < v.t;
        });
        if(it == event.begin()){
            cout << 0 << endl;
            continue;
        }
        it--;
        auto [pt, pw, ppos] = *it;
        cout <<  ppos + (t - pt) * pw << endl;

    }
    
    return 0;
}