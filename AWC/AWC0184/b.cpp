#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    string s;
    cin >> n >> s;
    bool check = false;
    int ans = 0;
    rep(i,n){
        if(!check && s[i] == '#'){
            check = true;
            ans++;
        }
        if(s[i] == '.') check = false;
    }

    cout << ans << endl;
    
    return 0;
}