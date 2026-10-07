#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int a, b;
    cin >> a >> b;

    bool ok = false;
    if(a + b == 9) ok = true;
    if(a - b == 9) ok = true;
    if(a * b == 9) ok = true;
    if(a % b == 0 && a / b == 9) ok = true;

    cout << (ok ? "Nine" : "Nein") << endl;
    
    return 0;
}