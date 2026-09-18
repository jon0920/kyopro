#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int r, g, b;
    string c;
    cin >> r >> g >> b >> c;
    if(c == "Red"){
        cout << (g <= b ? g : b) << endl;
    }
    else if(c == "Green"){
        cout << (r <= b ? r : b) << endl;
    }
    else{
        cout << (r <= g ? r : g) << endl;
    }
    
    return 0;
}