#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    vector<int> cnt(n + 1);
    rep(i,n){
        cin >> a[i];
        if(a[i] <= n) cnt[a[i]]++;
    }
    set<int> st;
    rep(i,n + 1){
        if(cnt[i] == 0) st.insert(i);
    }

    while(q--){
        int i, x;
        cin >> i >> x;
        i--;
        if(a[i] <= n){
            cnt[a[i]]--;
            if(cnt[a[i]] == 0) st.insert(a[i]);
        }
        if(x <= n){
            if(cnt[x] == 0) st.erase(x);
            cnt[x]++;
        }
        a[i] = x;
        cout << *st.begin() << endl;
    }
    
    return 0;
}