#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    string s;
    cin >> s;

    int pos = 0, ans = 0;
    int n = s.size();
    while(pos < n){
        ans++;
        if(pos+1 < n && s[pos] == '0' && s[pos+1] == '0') pos += 2;
        else pos++;
    }

    cout << ans << endl;
    
    return 0;
}