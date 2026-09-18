#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    string pre = t.substr(0,n), suf = t.substr(m - n, m);
    if(s == pre && s == suf) cout << 0 << endl;
    else if(s == pre && s != suf) cout << 1 << endl;
    else if(s != pre && s == suf) cout << 2 << endl;
    else cout << 3 << endl;
    
    return 0;
}