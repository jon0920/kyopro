#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int a, b, c;
    cin >> a >> b >> c;

    if(b > c && (c > a || b < a)) cout << "No" << endl;
    else if(b < c && b < a && a < c) cout << "No" << endl;
    else cout << "Yes" << endl;
    
    return 0;
}