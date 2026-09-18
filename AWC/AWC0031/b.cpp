#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n, t;
    cin >> n >> t;
    int ans = 0;
    rep(i,t){
        vector<int> s(n);
        rep(i,n) cin >> s[i];
        sort(s.rbegin(), s.rend());
        if(s[0] >= 2 * s[1]) ans++;
    }
    cout << ans << endl;

    return 0;
}