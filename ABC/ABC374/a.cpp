#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    string s;
    cin >> s;
    int n = s.size();
    string sub = s.substr(n - 3, 3);
    cout << (sub == "san" ? "Yes" : "No") << endl;
    return 0;
}