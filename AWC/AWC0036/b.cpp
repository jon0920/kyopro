#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int q;
    cin >> q;
    set<int> st;
    while(q--){
        int t, x;
        cin >> t >> x;
        if(t == 1){
            st.insert(x);
        } else {
            if(st.count(x)){
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
    }

    return 0;
}