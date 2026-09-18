#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n, l, r;
    cin >> n >> l >> r;
    string s;
    cin >> s;

    vector<int> cnt(26);
    rep(i,r-l+1){
        cnt[s[i+l] - 'a']++;
    }

    ll ans = 0;
    rep(i,n-l){
        ans += cnt[s[i] - 'a'];
        cnt[s[i + l] - 'a']--;
        if(i + r + 1 < n) cnt[s[i + r + 1] - 'a']++;
    }

    cout << ans << endl;

    return 0;
}