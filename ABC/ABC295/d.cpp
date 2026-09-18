#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    string s;
    cin >> s;

    ll ans = 0;
    vector<ll> cnt(1024);
    int cur = 0;
    cnt[cur] = 1;
    for(char c : s){
        int x = c - '0';
        cur ^= (1 << x);
        ans += cnt[cur];
        cnt[cur]++;
    }

    cout << ans << endl;
    
    return 0;
}