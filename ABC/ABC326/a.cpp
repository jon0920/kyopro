#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int x, y;
    cin >> x >> y;
    if((x > y && x - y <= 3) || (x < y && y - x <= 2)) cout << "Yes" << endl;
    else cout << "No" << endl;
    
    return 0;
}