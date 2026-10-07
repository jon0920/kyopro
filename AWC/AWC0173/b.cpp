#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int h, w;
    cin >> h >> w;
    vector<bool> col(w, true);
    rep(i,h){
        string s;
        cin >> s;
        rep(j,w){
            if(s[j] == '#') col[j] = false;
        }
    }

    int ans = 0;
    rep(i,w) if(col[i]) ans++;
    cout << ans << endl;
    
    return 0;
}