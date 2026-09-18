#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    string s;
    cin >> s;
    
    vector<pair<ll,ll>> p;
    ll n = s.size();
    int i = 0;
    while(i < n){
        int j = i + 1;
        while(j < n && s[i] == s[j]) j++;
        p.push_back({s[i] - '0', j - i});
        i = j;
    }

    ll ans = 0;
    ll m = p.size();
    rep(i,m-1){
        if(p[i].first == p[i+1].first - 1) ans += min(p[i].second, p[i+1].second);
    }

    cout << ans << endl;
    
    return 0;
}