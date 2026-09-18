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
        mp[a]++;
    }

    int ans = 0;
    for(auto [k, v] : mp){
        ans += v / 2;
    }

    cout << ans << endl;

    return 0;
}