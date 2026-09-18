#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int k, m;
    cin >> k >> m;
    set<int> st;
    rep(i,k){
        int a;
        cin >> a;
        st.insert(a);
    }

    int ans = 0;
    rep(i,m){
        int b;
        cin >> b;
        if(st.count(b)) ans++;
    }
    
    cout << ans << endl;
    
    return 0;
}