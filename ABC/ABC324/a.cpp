#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n;
    cin >> n;
    set<int> s;
    rep(i,n){
        int a;
        cin >> a;
        s.insert(a);
    }
    cout << (s.size() == 1 ? "Yes" : "No") << endl;
    
    return 0;
}