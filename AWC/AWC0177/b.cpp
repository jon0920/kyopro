#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    string s;
    cin >> n >> s;
    vector<bool> ok(n, false);
    rep(i,n){
        if(s[i] == 'G'){
            for(int j = i - 1; j <= i + 1; j++){
                if(j >= 0 && j < n) ok[j] = true;
            }
        }
    }
    int ans = 0;
    rep(i,n){
        if(!ok[i]) ans++;
    }
    cout << ans << endl;
    
    return 0;
}