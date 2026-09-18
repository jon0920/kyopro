#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int x;
    vector<int> a;
    while(cin >> x){
        a.push_back(x);
        if(x == 0) break;
    }
    reverse(a.begin(), a.end());
    rep(i,a.size()) cout << a[i] << endl;
    
    return 0;
}