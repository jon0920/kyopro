#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {

    int x1, y1, z1, x2, y2, z2;
    cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
    int x3, y3, z3, x4, y4, z4;
    cin >> x3 >> y3 >> z3 >> x4 >> y4 >> z4;

    bool c1 = true, c2 = true, c3 = true;
    if(x1 >= x4 || x2 <= x3) c1 = false;
    if(y1 >= y4 || y2 <= y3) c2 = false;
    if(z1 >= z4 || z2 <= z3) c3 = false;
    
    if(c1 && c2 && c3) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}