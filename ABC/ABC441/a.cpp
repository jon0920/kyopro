#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int p, q;
    int x, y;
    cin >> p >> q >> x >> y;

    for(int i = p; i < p + 100; i++){
        for(int j = q; j < q + 100; j++){
            if(i == x && j == y){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    
    return 0;
}