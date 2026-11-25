#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    cin >> n;
    string ans;
    rep(i,n){
        int a, b;
        cin >> a >> b;
        if((a + b) % 2 == 0) ans += "o";
        else ans += "x";
    }

    cout << ans << endl;
    
    return 0;
}