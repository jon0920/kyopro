#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i,h) cin >> s[i];

    int mx = -1, ans = -1;
    rep(i,w){
        int cnt = 0;
        rep(j,h){
            if(s[j][i] == 'F') cnt++;
        }
        if(mx < cnt){
            ans = i + 1;
            mx = cnt;
        }
    }
    cout << ans << endl;
    
    return 0;
}