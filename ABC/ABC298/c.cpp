#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n, q;
    cin >> n >> q;
    map<int,set<int>> cards;
    map<int,vector<int>> boxes;
    while(q--){
        int type;
        cin >> type;
        if(type == 1){
            int i, j;
            cin >> i >> j;
            boxes[j].push_back(i);
            cards[i].insert(j);
        }
        else if(type == 2){
            int i;
            cin >> i;
            sort(boxes[i].begin(), boxes[i].end());
            for(auto x : boxes[i]) cout << x << " ";
            cout << endl;
        }
        else{
            int i;
            cin >> i;
            for(auto x : cards[i]) cout << x << " ";
            cout << endl;
        }
    }
    
    return 0;
}