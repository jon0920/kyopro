#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    string s;
    cin >> s;
    int n = (s.size() - 1) / 2;
    s.erase(n,1);
    cout << s << endl;
    
    return 0;
}