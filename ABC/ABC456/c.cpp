#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
using mint = modint998244353;

int main(){

    string s;
    cin >> s;
    int n = s.size();
    vector<ll> seg;
    ll cnt = 1;
    char last = s[0];
    for(int i = 1; i < n; i++){
        if(s[i] == last){
            seg.push_back(cnt);
            cnt = 1;
        } else {
            cnt++;
            last = s[i];
        }
    }
    seg.push_back(cnt);

    mint ans = 0;
    for(auto x : seg){
        ans += x * (x + 1) / 2;
    }

    cout << ans.val() << endl;

    return 0;
}