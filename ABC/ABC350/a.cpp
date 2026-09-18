#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    string s;
    cin >> s;
    string sub = s.substr(3);
    int n = stoi(sub);
    if(n < 350 && n != 316 && n >= 1) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}