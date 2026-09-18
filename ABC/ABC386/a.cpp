#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    set<int> a;
    rep(i,4){
        int k;
        cin >> k;
        a.insert(k);
    }

    cout << (a.size() == 2 ? "Yes" : "No") << endl;
    
    return 0;
}