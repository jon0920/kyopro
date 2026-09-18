#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int a, b, d;
    cin >> a >> b >> d;
    cout << a << " ";
    while(a != b){
        cout << a + d << " ";
        a += d;
    }
    cout << endl;
    return 0;
}