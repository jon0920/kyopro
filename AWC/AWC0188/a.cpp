#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, a, b;
    cin >> n >> a >> b;

    cout << (n * a <= b ? "Yes" : "No") << endl;
    
    return 0;
}