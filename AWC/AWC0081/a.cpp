#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    cin >> n;
    int ans = 0;
    rep(i,n){
        string s, t;
        cin >> s >> t;
        if(s != t) ans++;
    }

    cout << ans << endl;
    
    return 0;
}