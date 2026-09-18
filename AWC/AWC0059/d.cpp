#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n;
    string s;
    cin >> n >> s;
    vector<int> a(n);
    int cnt = 0;
    rep(i,n){
        if(s[i] == 'V') cnt++;
        else if(s[i] == 'F') cnt--;

        a[i] = cnt;
    }

    map<int,int> mp;
    mp[0] = 1;
    ll ans = 0;
    for(auto x : a){
        if(mp.count(x)) ans += mp[x];
        mp[x]++;
    }

    cout << ans << endl;

    return 0;
}