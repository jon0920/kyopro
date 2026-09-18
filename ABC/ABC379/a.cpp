#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n;
    cin >> n;

    int c = n % 10;
    n /= 10;
    int b = n % 10;
    n /= 10;
    int a = n;
    
    cout << b << c << a << " ";
    cout << c << a << b << endl;
    
    return 0;
}