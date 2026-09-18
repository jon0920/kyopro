#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n;
    cin >> n;
    vector<string> s(n);
    int mx = 0;
    rep(i,n){
        cin >> s[i];
        mx = max(mx, (int)s[i].size());
    }

    rep(i,n){
        int sz = s[i].size();
        int dot = (mx - sz) / 2;
        rep(j,dot) cout << '.';
        cout << s[i];
        rep(j,dot) cout << '.';
        cout << endl;
    }

    return 0;
}