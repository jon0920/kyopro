#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n;
    cin >> n;
    map<int,int> mp;
    rep(i,n){
        int a;
        cin >> a;
        if(!mp.count(a - 1)){
            mp[a] = 1;
        }
        else{
            mp[a] = mp[a - 1] + 1;
        }
    }

    int ans = 0;
    for(auto [k, v] : mp){
        ans = max(ans, v);
    }
    cout << ans << endl;

    return 0;
}