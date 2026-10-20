#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int h, w;
    cin >> h >> w;
    int ans = 0;
    rep(i,h){
        string s;
        cin >> s;
        bool ok = true;
        for(char c : s) if(c == 'x') ok = false;
        if(ok) ans++;
    }
    cout << ans << endl;
    
    return 0;
}