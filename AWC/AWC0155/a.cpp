#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    cin >> n;
    int mx = 0;
    string t = "tanabata";
    int ans = 1;
    rep(i,n){
        string s;
        cin >> s;
        if(s.size() <= 7) continue;
        int cnt = 0;
        rep(j,s.size() - 7){
            if(s.substr(j,8) == t) cnt++;
        }
        if(mx < cnt){
            ans = i + 1;
            mx = cnt;
        }
    }

    cout << ans << endl;
    
    return 0;
}