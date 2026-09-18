#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int xa, ya, xb, yb, xc, yc;
    cin >> xa >> ya >> xb >> yb >> xc >> yc;

    int a1, a2, b1, b2, c1, c2;
    a1 = xb - xa, a2 = yb - ya;
    b1 = xc - xb, b2 = yc - yb;
    c1 = xa - xc, c2 = ya - yc;

    int ans1 = a1 * b1 + a2 * b2;
    int ans2 = b1 * c1 + b2 * c2;
    int ans3 = c1 * a1 + c2 * a2;
    
    if(ans1 == 0 || ans2 == 0 || ans3 == 0) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}