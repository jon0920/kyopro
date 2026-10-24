#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    vector<pair<int,int>> p(3);
    for(int i = 1; i <= 3; i++){
        int v;
        cin >> v;
        p[i - 1] = {v, -i};
    }
    sort(p.rbegin(), p.rend());

    cout << -p[0].second << endl;
    
    return 0;
}