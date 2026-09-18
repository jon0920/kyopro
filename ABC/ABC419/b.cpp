#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int q;
    cin >> q;
    priority_queue<int, vector<int>, greater<int>> pq;
    rep(i,q){
        int type;
        cin >> type;
        if(type == 1){
            int x;
            cin >> x;
            pq.push(x);
        } else {
            cout << pq.top() << endl;
            pq.pop();
        }
    }
    
    return 0;
}