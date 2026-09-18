#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    string t;
    cin >> n >> t;
    int sz = t.size();
    vector<pair<int,int>> pre_suf(n);
    rep(i,n){
        string s;
        cin >> s;
        int m = s.size();
        int cur = 0;
        rep(j,m){
            if(s[j] == t[cur]) cur++;
            if(cur == sz) break;
        }
        pre_suf[i].first = cur;
        cur = sz;
        for(int j = m - 1; j >= 0; j--){
            if(s[j] == t[cur - 1]) cur--;
            if(cur == 0) break;
        }
        pre_suf[i].second = sz - cur;
    }

    vector<int> pre(n), suf(n);
    rep(i,n){
        pre[i] = pre_suf[i].first;
        suf[i] = pre_suf[i].second;
    }
    sort(pre.begin(), pre.end());
    sort(suf.begin(), suf.end());

    ll ans = 0;
    for(auto [x, _] : pre_suf){
        ll cnt = suf.end() - lower_bound(suf.begin(), suf.end(), sz - x);
        ans += cnt;
    }

    cout << ans << endl;
    
    return 0;
}