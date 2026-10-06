#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    string s;
    cin >> n >> s;
    int ans = 0;
    for(char c : s) ans = max(ans, c - '0');
    cout << ans << endl;
    
    return 0;
}