#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int a;
    set<int> st;
    rep(i,3){
        cin >> a;
        st.insert(a);
    }
    cout << (st.size() <= 2 ? "Yes" : "No") << endl;
    
    return 0;
}