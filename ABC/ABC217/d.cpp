#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int l, q;
    cin >> l >> q;
    set<int> st = {0, l};

    while(q--){
        int c, x;
        cin >> c >> x;
        if(c == 1){
            st.insert(x);
        } else {
            auto it = st.upper_bound(x);
            cout << *it - *prev(it) << endl;
        }
    }
    
    return 0;
}