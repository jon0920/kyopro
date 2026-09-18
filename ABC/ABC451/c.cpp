#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int q;
    cin >> q;
    priority_queue<int, vector<int>, greater<int>> pq;
    while(q--){
        int type, h;
        cin >> type >> h;
        if(type == 1){
            pq.push(h);
        } else {
            while(!pq.empty() && pq.top() <= h) pq.pop();
        }
        cout << pq.size() << endl;
    }

    return 0;
}