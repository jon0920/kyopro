#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    map<string,int> m;
    m["Ocelot"] = 1, m["Serval"] = 2, m["Lynx"] = 3;
    
    string x, y;
    cin >> x >> y;
    cout << (m[x] >= m[y] ? "Yes" : "No") << endl;
    
    return 0;
}