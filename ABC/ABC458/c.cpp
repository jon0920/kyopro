#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    string s;
    cin >> s;
    int n = s.size();
    ll ans = 0;
    rep(i,n){
        if(s[i] == 'C'){
            ll left = i + 1;
            ll right = n - i;
            ans += min(left, right);
        }
    }

    cout << ans << endl;
    
    return 0;
}