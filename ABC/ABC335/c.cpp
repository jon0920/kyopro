#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n, q;
    cin >> n >> q;
    deque<pair<int,int>> pos;
    for(int i = 1; i <= n; i++) pos.push_back({i,0});
    
    int nx = 1, ny = 0;
    while(q--){
        int type;
        cin >> type;
        if(type == 1){
            char c;
            cin >> c;
            if(c == 'L') nx--;
            else if(c == 'R') nx++;
            else if(c == 'U') ny++;
            else ny--;
            pos.push_front({nx, ny});
            pos.pop_back();
        }
        else{
            int p;
            cin >> p;
            p--;
            cout << pos[p].first << " " << pos[p].second << endl;
        }
    }
    
    return 0;
}