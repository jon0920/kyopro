#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    map<int,int> mp;
    rep(i,n){
        cin >> a[i];
        mp[a[i]]++;
    }

    ll ans = 0;
    for(int x : a){
        ll y = k - x;
        if(mp.count(y)){
            if(y == x) ans += mp[y] - 1;
            else ans += mp[y];
        }
        mp[x]--;
    }

    cout << ans << endl;
    
    return 0;
}