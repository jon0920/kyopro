#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n;
    cin >> n;
    vector<string> s(n);
    rep(i,n) cin >> s[i];
    int x;
    string y;
    cin >> x >> y; x--;
    cout << (s[x] == y ? "Yes" : "No") << endl;
    
    return 0;
}