#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n;
    cin >> n;
    int x = 0, y = 0, z = 0;
    while(x + y + z <= n){
        while(x + y + z <= n){
            while(x + y + z <= n){
                cout << x << " " << y << " " << z << endl;
                z++;
            }
            z = 0;
            y++;
        }
        y = 0;
        x++;
    }
    
    
    return 0;
}