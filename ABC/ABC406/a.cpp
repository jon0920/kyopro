#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    bool flag = 1;

    if(a < c) flag = 0;
    if(a == c && b < d) flag = 0;

    cout << (flag ? "Yes" : "No") << endl;
    
    return 0;
}