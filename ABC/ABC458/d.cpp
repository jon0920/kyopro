#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int x, q;
    cin >> x >> q;
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;
    left.push(x);
    while(q--){
        int a, b;
        cin >> a >> b;
        if(a <= left.top()) left.push(a);
        else right.push(a);

        if(b <= left.top()) left.push(b);
        else right.push(b);

        while(left.size() > right.size() + 1){
            right.push(left.top());
            left.pop();
        }
        while(left.size() < right.size() + 1){
            left.push(right.top());
            right.pop();
        }

        cout << left.top() << endl;
    }
    
    return 0;
}