#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int q;
    cin >> q;
    map<int,int> mp;
    int ans = 0;
    rep(i,q){
        int type;
        cin >> type;
        if(type == 1){
            int x;
            cin >> x;
            if(mp[x] == 0) ans++;
            mp[x]++;
        }
        else if(type == 2){
            int x;
            cin >> x;
            if(mp[x] == 1) ans--;
            mp[x]--;
        }
        else{
            cout << ans << endl;
        }
    }
    
    return 0;
}