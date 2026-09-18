#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];

    map<int,int> mp;
    rep(i,n){
        if(mp.find(a[i]) != mp.end()){
            cout << mp[a[i]] << endl;
        }
        else cout << -1 << endl;
        mp[a[i]] = i + 1;
    }
    
    return 0;
}