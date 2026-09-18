#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int q;
    cin >> q;
    map<int,int> mp;    
    set<int> st;
    
    while(q--){
        int type;
        cin >> type;
        if(type == 1){
            int x;
            cin >> x;
            mp[x]++;
            st.insert(x);
        }
        else if(type == 2){
            int x, c;
            cin >> x >> c;
            if(mp[x] > c) mp[x] -= c;
            else{
                mp.erase(x);
                st.erase(x);
            }
        }
        else{
            int mx = *st.rbegin();
            int mn = *st.begin();
            cout << mx - mn << endl;
        }
    }

    return 0;
}