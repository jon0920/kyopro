#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int M, D;
    int y, m, d;
    cin >> M >> D >> y >> m >> d;
    if(M == m && D == d){
        y++; m = 1; d = 1;
    }
    else if(D == d){
        m++; d = 1;
    }
    else d++;
    cout << y << " " << m << " " << d << endl;
    
    return 0;
}