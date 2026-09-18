#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    string s;
    cin >> s;

    string t = "atcoder";
    map<char,int> mp;
    rep(i,7) mp[t[i]] = i;

    vector<int> a(7);
    rep(i,7) a[i] = mp[s[i]];

    fenwick_tree<int> fw(7);
    int ans = 0;

    rep(i,7){
        ans += i - fw.sum(0, a[i]);
        fw.add(a[i], 1);
    }
    cout << ans << endl;

    return 0;
}