#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int x, y, z;
    cin >> x >> y >> z;
    
    while(1){
        if(x == y * z){
            cout << "Yes" << endl;
            return 0;
        }
        if(x < y * z){
            cout << "No" << endl;
            return 0;
        }
        x++; y++;
    }
    
    return 0;
}