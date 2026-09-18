#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n;
    cin >> n;
    vector<int> cnt(26);
    rep(i,n){
        string s;
        cin >> s;
        cnt[s[0] - 'a']++;
    }

    int ans = 0;
    for(int x : cnt) ans = max(ans, x);

    cout << ans << endl;

    return 0;
}