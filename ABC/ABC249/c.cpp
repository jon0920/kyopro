#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n, k;
    cin >> n >> k;
    vector<string> s(n);
    rep(i,n) cin >> s[i];

    int ans = 0;
    for(int bit = 0; bit < (1 << n); bit++){
        vector<int> cnt(26);
        int res = 0;
        rep(i,n) if((bit >> i) & 1){
            for(char c : s[i]) cnt[int(c - 'a')]++;
        }
        for(int x : cnt) if(x == k) res++;
        ans = max(ans, res);
    }
    cout << ans << endl;

    return 0;
}