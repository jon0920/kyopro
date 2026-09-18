#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    string s;
    cin >> s;
    int n = s.size();
    vector<ll> cnt(26), sum(26);
    ll ans = 0;
    rep(i,n){
        int v = s[i] - 'A';
        ans += (i - 1) * cnt[v] - sum[v];
        cnt[v]++;
        sum[v] += i;
    }
    cout << ans << endl;
    
    return 0;
}