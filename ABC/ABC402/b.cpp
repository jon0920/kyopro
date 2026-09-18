#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int q;
    cin >> q;
    vector<int> que;
    rep(i,q){
        int type;
        cin >>type;
        if(type == 1){
            int x;
            cin >> x;
            que.push_back(x);
        }
        else{
            cout << que[0] << endl;
            que.erase(que.begin());
        }
    }
    
    return 0;
}