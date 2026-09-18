#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    string s;
    cin >> s;

    while(s.back() == '0') s.pop_back();
    if(s.back() == '.') s.pop_back();

    cout << s << endl;
    
    return 0;
}