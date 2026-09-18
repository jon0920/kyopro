#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n, k;
    cin >> n >> k;
    vector<int> p(n);
    set<int> st;
    rep(i,n){
        cin >> p[i];
        if(i < k) st.insert(p[i]);
    }

    cout << *st.begin() << endl;
    for(int i = k; i < n; i++){
        if(*st.begin() > p[i]) cout << *st.begin() << endl;
        else{
            st.erase(*st.begin());
            st.insert(p[i]);
            cout << *st.begin() << endl;
        }
    } 

    return 0;
}