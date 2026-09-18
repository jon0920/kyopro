#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    string s;
    cin >> s;
    int n = s.size();
    int ans = 0, d = 0;
    for(int i = 1; i < n; i++){
        if(s[i - 1] == '(') d++;
        else d--;
        ans = max(ans, d);
    }
    cout << ans << endl;
    
    return 0;
}