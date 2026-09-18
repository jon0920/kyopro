#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int q;
    cin >> q;
    stack<int> s;
    
    rep(i,q){
        int type;
        cin >> type;
        if(type == 1){
            int x;
            cin >> x;
            s.push(x);
        }
        else{
            if(s.empty()) cout << 0 << endl;
            else{
                cout << s.top() << endl;
                s.pop();
            }
        }
    }
    
    return 0;
}