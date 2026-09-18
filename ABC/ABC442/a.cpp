#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    string s;
    cin >> s;
    int ans = 0;
    for(auto c : s) if(c == 'i' || c == 'j') ans++;
    cout << ans << endl;
    
    return 0;
}