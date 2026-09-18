#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int a, b;
    cin >> a >> b;
    if(a == b){
        cout << 1 << endl;
        return 0;
    }
    cout << (abs(a - b) % 2 == 0 ? 3 : 2) << endl;
    
    return 0;
}