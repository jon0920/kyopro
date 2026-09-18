#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    map<int,int> mp;
    rep(i,4){
        int b;
        cin >> b;
        mp[b]++;
    }

    int ans = 0;
    for(auto [a, cnt] : mp){
        if(cnt == 2 || cnt == 3) ans++;
        if(cnt == 4) ans += 2;
    }
    
    cout << ans << endl;
    
    return 0;
}