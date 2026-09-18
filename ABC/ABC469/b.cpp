#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    string s;
    cin >> n >> s;

    int ans = 0;
    rep(i,n){
        bool c1 = false, c2 = false, c3 = false;
        if(i != 0 && s[i - 1] == 'o') c1 = true;
        if(i != n - 1 && s[i + 1] == 'o') c3 = true;
        if(s[i] == 'o') c2 = true;

        if(!c1 && !c2 && !c3) ans++;
    }

    cout << ans << endl;
    
    return 0;
}