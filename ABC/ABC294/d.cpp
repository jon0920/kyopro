#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n, q;
    cin >> n >> q;
    queue<int> call1, call2;
    rep(i,n) call1.push(i);
    vector<bool> checked(n,false);
    while(q--){
        int type;
        cin >> type;
        if(type == 1){
            call2.push(call1.front());
            call1.pop();
        }
        else if(type == 2){
            int x;
            cin >> x;
            x--;
            checked[x] = true;
        }
        else{
            while(checked[call2.front()]) call2.pop();
            cout << call2.front() + 1 << endl;
        }
    }
    
    return 0;
}