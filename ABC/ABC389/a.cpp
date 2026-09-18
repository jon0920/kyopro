#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    string s;
    cin >> s;
    
    int a = s[0] - '0';
    int b = s[2] - '0';
    cout << a * b << endl;
    
    return 0;
}