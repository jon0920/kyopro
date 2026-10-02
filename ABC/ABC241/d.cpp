#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int q;
    cin >> q;
    multiset<ll> st;
    while(q--){
        int type;
        cin >> type;
        if(type == 1){
            ll x;
            cin >> x;
            st.insert(x);
        } else if(type == 2){
            ll x; int k;
            cin >> x >> k;
            k--;
            auto it = st.upper_bound(x);
            if(it == st.begin()){
                cout << -1 << endl;
                continue;
            }
            it--;
            bool ok = true;
            while(k--){
                if(it == st.begin()){
                    ok = false;
                    break;
                }
                it--;
            }
            if(ok) cout << *it << endl;
            else cout << -1 << endl;
        } else {
            ll x; int k;
            cin >> x >> k;
            k--;
            auto it = st.lower_bound(x);
            while(k--){
                if(it == st.end()) break;
                it++;
            }
            if(it == st.end()){
                cout << -1 << endl;
            } else {
                cout << *it << endl;
            }
        }
    }
    
    return 0;
}