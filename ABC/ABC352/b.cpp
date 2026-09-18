#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    string s, t;
    cin >> s >> t;

    int n = s.size(), m = t.size();
    int now = 0;
    rep(i,n){
        while(s[i] != t[now]) now++;
        cout << now + 1 << " ";
        now++;
    }
    cout << endl;
    return 0;
}