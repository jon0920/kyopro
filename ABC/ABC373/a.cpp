#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    vector<string> s(12);
    rep(i,12) cin >> s[i];

    int ans = 0;
    rep(i,12){
        if(s[i].size() == i + 1) ans++;
    }
    
    cout << ans << endl;
    return 0;
}