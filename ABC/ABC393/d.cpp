#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n;
    string s;
    cin >> n >> s;
    int c1 = 0;
    for(char c : s) if(c == '1') c1++;

    int now = 0;
    ll ans = 0;
    for(char c : s){
        if(c == '0') ans += min(now, c1 - now);
        else now++;
    }
    cout << ans << endl;
    
    return 0;
}