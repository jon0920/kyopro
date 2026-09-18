#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    string s;
    cin >> n >> s;
    int ans = 0;
    rep(i,n) if(s[i] == 'o') ans++;
    cout << ans << endl;
    
    return 0;
}