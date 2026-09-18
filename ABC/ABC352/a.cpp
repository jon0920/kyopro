#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n, x, y, z;
    cin >> n >> x >> y >> z;
    if(x < y){
        for(int i = x; i <= y; i++){
            if(i == z){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    else{
        for(int i = y; i <= x; i++){
            if(i == z){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    
    return 0;
}