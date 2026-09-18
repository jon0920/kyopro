#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n, q;
    cin >> n >> q;
    
    vector<int> front(n, -1), back(n, -1);

    while(q--){
        int type;
        cin >> type;
        if(type == 1){
            int x, y;
            cin >> x >> y;
            x--, y--;
            back[x] = y;
            front[y] = x;
        }
        else if(type == 2){
            int x, y;
            cin >> x >> y;
            x--, y--;
            back[x] = -1;
            front[y] = -1;
        }
        else{
            int x;
            cin >> x;
            x--;
            while(front[x] != -1){
                x = front[x];
            }
            vector<int> res;
            while(x != -1){
                res.push_back(x);
                x = back[x];
            }

            cout << res.size() << " ";
            for(auto v : res) cout << v + 1 << " ";
            cout << endl;
        }
    }

    return 0;
}