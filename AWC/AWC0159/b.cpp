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
        if(mp.count(x + k)) ans += mp[x + k];
    }

    cout << ans << endl;
    
    return 0;
}