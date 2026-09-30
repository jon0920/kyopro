#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    string s, t;
    cin >> n >> s >> t;
    int ans = 0;
    int cnt = 0;
    rep(i,n){
        if(s[i] == t[i]){
            cnt++;
        } else {
            ans = max(ans, cnt);
            cnt = 0;
        }
    }
    ans = max(ans, cnt);

    cout << ans << endl;
    
    return 0;
}