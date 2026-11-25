#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    cin >> n;
    string ans;
    rep(i,n){
        int a;
        cin >> a;
        if(a == 0) ans += "-";
        else if(a == 10) ans += "X";
        else ans += a + '0';
    }

    cout << ans << endl;
    
    return 0;
}