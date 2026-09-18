#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n;
    cin >> n;
    vector<string> s(n);
    rep(i,n) cin >> s[i];

    string ans = "";
    for(int i = 1; i <= 50; i++){
        rep(j,n){
            if(s[j].size() == i) ans += s[j];
        }
    }
    rep(i,n) cout << ans[i];
    cout << endl;
    return 0;
}