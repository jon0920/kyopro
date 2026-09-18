#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int q;
    cin >> q;
    vector<int> a;
    rep(i,q){
        int type;
        cin >> type;
        if(type == 1){
            int x;
            cin >> x;
            a.push_back(x);
        }
        else{
            int k;
            cin >> k;
            cout << (a[a.size() - k]) << endl;
        }
    }
    
    return 0;
}